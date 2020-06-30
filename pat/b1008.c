#include <stdio.h>

int N;
int M;
int ms[100];

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    scanf("%d %d", &N, &M);
    M = M%N;
    int offset = gcd(N, M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", ms+i);
    }

    if (offset != 0) {
        for (int j = N-M; j < N; ++j) {
            int tmp = ms[j];
            int pos = j;
            do {
                int pre = (pos-offset+N)%N;
                if (pre != j) ms[pos] = ms[pre];
                else ms[pos] = tmp;
                pos = pre;
            } while (pos != j);
        }
    }
    if (N>0)
        printf("%d", ms[0]);
    for (int k = 1; k < N; ++k) {
        printf(" %d", ms[k]);
    }
    printf("\n");

    return 0;
}