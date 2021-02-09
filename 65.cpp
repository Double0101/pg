#include <cstdio>

typedef long long LL;

int main()
{
    int i;
    LL a, b, c, t;
    scanf("%d", &i);
    for (int j = 1; j <= i; ++j) {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("Case #%d: ", j);
        t = a+b;
        if (a > 0 && b > 0) {
            if (t < 0 || (t > 0 && t > c)) printf("true\n");
            else printf("false\n");
            continue;
        } else if (a < 0 && b < 0) {
            if (t < 0 && t > c) printf("true\n");
            else printf("false\n");
            continue;
        } else {
            if (t > c) printf("true\n");
            else printf("false\n");
            continue;
        }
    }
    return 0;
}