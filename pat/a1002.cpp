#include <cstdio>

double items[1001] = {0};

int main()
{
    int co = 0;
    for (int i = 0; i < 2; ++i) {
        int c;
        scanf("%d", &c);
        for (int j = 0; j < c; ++j) {
            int n1;
            double n2;
            scanf("%d%lf", &n1, &n2);
            items[n1] += n2;
        }
    }

    for (int l = 0; l < 1001; ++l) {
        if (items[l] != 0) ++co;
    }

    printf("%d", co);
    for (int k = 1000; k >= 0; --k) {
        if (items[k] != 0) {
            printf(" %d %.1lf", k, items[k]);
        }
    }
    printf("\n");
    return 0;
}