#include <stdio.h>

char code[] = {'0','1','2','3','4','5','6','7','8','9'};
char ans[11];

int main()
{
    ans[10] = '\0';
    int a, b, i = 9;
    int sign = 1;
    scanf("%d%d", &a, &b);

    a += b;
    if (a < 0) {
        sign = -1;
        a = 0-a;
    }
    if (a == 0) {
        printf("0\n");
        return 0;
    }
    while (a > 0) {
        if (i == 6 || i == 2) {
            ans[i--] = ',';
        }
        ans[i--] = code[a%10];
        a = a / 10;
    }
    if (sign == -1) {
        ans[i--] = '-';
    }
    ++i;
    printf("%s\n", ans+i);

    return 0;
}