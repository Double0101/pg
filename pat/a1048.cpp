#include <stdio.h>

int cnum, price;

int coins[1001];

int main()
{
    scanf("%d %d", &cnum, &price);
    for (int i = 0; i < cnum; ++i) {
        int a;
        scanf("%d", &a);
        ++coins[a];
    }

    for (int j = 1; j < price/2; ++j) {
        if (coins[j] != 0 && coins[price-j] != 0) {
            if (j == price - j && coins[j] <= 1) continue;
            printf("%d %d\n", j, price - j);
            return 0;
        }
    }
    printf("No Solution\n");

    return 0;
}