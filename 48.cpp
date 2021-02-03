#include <cstdio>

int coin[501] = {0};
int N, price;

int main()
{
    scanf("%d%d", &N, &price);
    for (int i = 0; i < N; ++i) {
        int a;
        scanf("%d", &a);
        ++coin[a];
    }
    int p = price/2;
    for (int i = 1; i <= p; ++i) {
        if (coin[i] > 0) {
            int b = price-i;
            if (b == i && coin[i] > 1) {
                printf("%d %d\n", i, i);
                return 0;
            }
            if (b != i && coin[b] > 0) {
                printf("%d %d\n", i, b);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}