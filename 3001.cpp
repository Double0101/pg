#include <cstdio>
#include <cstdlib>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    a += b;
    if (a == 0) {
        printf("0\n");
        return 0;
    }
    if (a < 0) {
        printf("-");
        a = 0-a;
    }
    int flag = 10000000;
    while (flag > a) flag/=10;
    while (flag > 0) {
        printf("%d", a/flag);
        if (flag == 1000000 || flag == 1000) printf(",");
        a %= flag;
        flag /= 10;
    }
    printf("\n");
    return 0;
}
