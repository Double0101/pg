#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int N, n;
vector<int> ori, in;

void buildHeap(int root) {
    int lc = root*2+1, rc = lc+1, next = root;
    if (lc < n && ori[next] < ori[lc]) next = lc;
    if (rc < n && ori[next] < ori[rc]) next = rc;
    if (next == root) return;
    int tmp = ori[root];
    ori[root] = ori[next];
    ori[next] = tmp;
    buildHeap(next);
}

int main()
{
    scanf("%d", &N);
    ori.resize(N), in.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ori[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &in[i]);
    }
    int i, j;
    for (i = 0; i < N-1 && in[i] <= in[i+1]; ++i);
    for (j = i+1; j < N && in[j]==ori[j]; ++j);
    if (j == N) {
        printf("Insertion Sort\n");
        sort(in.begin(), in.begin()+i+2);
    } else {
        printf("Heap Sort\n");
        n = N;
        ori = in;
        for (n = N; n > 0 && in[0] <= in[n-1]; --n);
        int m = ori[0];
        ori[0] = ori[n-1];
        ori[n-1] = m;
        --n;
        buildHeap(0);
        in = ori;
    }
    for (int k = 0; k < N - 1; ++k) {
        printf("%d ", in[k]);
    }
    printf("%d\n", in[N-1]);
    return 0;
}
