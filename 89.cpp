#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;  // st == 0 Merge Sort
    scanf("%d", &N);
    vector<int> ori(N), in(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(ori[i]));
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(in[i]));
    }
    int i, j;
    for (i = 0; i < N-1 && in[i] <= in[i+1]; ++i);
    for (j = i+1; j < N && ori[j] == in[j]; ++j);
    if (j == N) {
        printf("Insertion Sort\n");
        sort(in.begin(), in.begin()+i+2);
    } else {
        printf("Merge Sort\n");
        int flag = 1, span = 1;
        while (flag) {
            flag = 0;
            for (int k = 0; k < N; ++k) {
                if (in[k] != ori[k])
                    flag = 1;
            }
            span *= 2;
            for (int k = 0; k < N / span; ++k) {
                sort(ori.begin()+k*span, ori.begin()+k*span+span);
            }
            sort(ori.begin()+N/span*span, ori.begin()+N);
        }
        in = ori;
    }
    for (int i = 0; i < N; ++i) {
        if (i != 0) printf(" ");
        printf("%d", in[i]);
    }
    printf("\n");
    return 0;
}
