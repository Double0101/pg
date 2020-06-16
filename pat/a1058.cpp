#include <stdio.h>


int main()
{
    int a1, b1, c1, a2, b2, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    a1 += a2;
    b1 += b2;
    c1 += c2;
    b1 += c1/29;
    c1 = c1%29;
    a1 += b1/17;
    b1 = b1%17;

    printf("%d.%d.%d\n", a1, b1, c1);
    return 0;
}