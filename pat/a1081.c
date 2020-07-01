#include <stdio.h>

typedef long long LL;

LL numerators[110];
LL denominators[110];

int N;

LL gcd(LL a, LL b)
{
    if (b==0) return a;
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld/%lld", numerators+i, denominators+i);
    }
    LL num=0, den=1, denn, denon;
    for (int j = 0; j < N; ++j) {
        LL g = gcd(den, denominators[j]);
        denn = den/g;
        denon = denominators[j]/g;
        num *= denon;
        num += numerators[j]*denn;
        den *= denon;
        g = gcd(den, num);
        num /= g;
        den /= g;
    }

    LL a = num%den;
    LL d = num/den;
    if (a == 0)
        printf("%lld\n", d);
    else if (d == 0)
        printf("%lld/%lld\n", a, den);
    else
        printf("%lld %lld/%lld\n", d, a, den);
    return 0;
}
