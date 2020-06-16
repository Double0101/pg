#include <cstdio>

int ans[50];

int main()
{
    int num, b;
    scanf("%d %d", &num, &b);
    int i = 49;
    while (num > 0) {
        ans[i--] = num % b;
        num = num / b;
    }
    
    while (ans[i] == 0) ++i;

    int j = i, k = 49;
    int a = 1;
    for ( ; j != k; ++j, --k) {
        if (ans[j] != ans[k]) {
            a = 0;
            break;
        }
    }

    if (a == 1)
        printf("Yes\n");
    else
        printf("No\n");

    for (; i < 49; ++i) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[i]);
    return 0;
}