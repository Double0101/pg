#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> ori, input;

void buildHeap(int start, int end)
{
    if (start > end) return;
    int lc = start*2+1, rc = lc+1;
    int max = start;
    if (lc <= end && input[max] < input[lc]) max = lc;
    if (rc <= end && input[max] < input[rc]) max = rc;
    if (max != start) {
        int tmp = input[max];
        input[max] = input[start];
        input[start] = tmp;
        buildHeap(max, end);
    }
}

int main()
{
    scanf("%d", &N);
    ori.resize(N);
    input.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ori[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &input[i]);
    }
    int i, j;
    for (i = 1; i < N && input[i] >= input[i-1]; ++i);
    for (j = i; j < N && input[j] == ori[j]; ++j);
    if (j == N) {
        printf("Insertion Sort\n");
        sort(input.begin(), input.begin()+i+1);
    } else {
        printf("Heap Sort\n");
        int top = input[0];
        int k;
        for (k = N-1; k > 0 && input[k] >= top; --k);
        input[0] = input[k];
        input[k] = top;
        buildHeap(0, k-1);
    }
    for (int k = 0; k < N - 1; ++k) {
        printf("%d ", input[k]);
    }
    printf("%d\n", input[N-1]);
    return 0;
}
