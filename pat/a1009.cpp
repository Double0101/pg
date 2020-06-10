#include <stdio.h>

double items[1001] = {0};
double ans[2001] = {0};

int main()
{
    int cc;
    scanf("%d", &cc);

    for (int i = 0; i < cc; ++i) {
        int a;
        double cd;
        scanf("%d%lf", &a, &cd);
        items[a] = cd;
    }
    scanf("%d", &cc);
    for (int j = 0; j < cc; ++j) {
        int a;
        double cd;
        scanf("%d%lf", &a, &cd);
        for (int i = 0; i < 1001; ++i) {
            if (items[i] != 0) {
                ans[i+a] += cd*items[i];
            }
        }
    }
    int ccc = 0;
    for (int k = 0; k < 2001; ++k) {
        if (ans[k] != 0)
            ++ccc;
    }
    printf("%d", ccc);
    for (int l = 2000; l >= 0; --l) {
        if (ans[l] != 0)
            printf(" %d %.1lf", l, ans[l]);
    }
    printf("\n");

    return 0;
}