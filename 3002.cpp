#include <cstdio>
#include <cstdlib>

double items[1005];

int main()
{
    int K, N;
    double A;
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &K);
        for (int j = 0; j < K; ++j) {
            scanf("%d%lf", &N, &A);
            items[N] += A;
        }
    }
    int count = 0;
    for (N = 1000; N >= 0; --N) {
        if (items[N] != 0) ++count;
    }
    printf("%d", count);
    for (N = 1000; N >= 0; --N) {
        if (items[N] != 0) {
            printf(" %d %.01lf", N, items[N]);
        }
    }
    printf("\n");
    return 0;
}
