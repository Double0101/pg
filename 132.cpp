#include <cstdio>

typedef long long LL;
int N;

int main()
{
    LL num, t, a, b, c;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &num);
        t = 1;
        a = 0;
        b = num;
        while (a > t || b > t) {
            t *= 10;
            a = num%t;
            b = num/t;
        }
        c = a*b;
        if (c != 0 && num%c == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
