#include <cstdio>

typedef long long LL;

int gcd(LL a, LL b)
{
    if (b == 0 || a%b == 0) return b;
    return gcd(b, a%b);
}

void print(LL num, LL den) {
    if (den == 0) {
        printf("Inf");
        return;
    }
    bool flag = false;
    if (num < 0) {
        flag = true;
        num = 0-num;
    }
    if (flag) printf("(-");
    LL i = num/den;
    if (i != 0 && den != 1) {
        printf("%lld %lld/%lld", i, num%den, den);
    }
    else if (den == 1) printf("%lld", num);
    else printf("%lld/%lld", num%den, den);
    if (flag) printf(")");
}
LL nume[2], deno[2];
void fpri(char c, LL num, LL den)
{
    LL l = gcd(num, den);
    if (l == 0) l = 1;
    num /= l;
    den /= l;
    if (den < 0) {
        den = 0-den;
        num = 0-num;
    }

    print(nume[0], deno[0]);
    printf(" %c ", c);
    print(nume[1], deno[1]);
    printf(" = ");
    print(num, den);
    printf("\n");
}
int main()
{
    scanf("%lld/%lld %lld/%lld", &(nume[0]), &(deno[0]), &(nume[1]), &(deno[1]));
    for (int i = 0; i < 2; ++i) {
        LL l = gcd(nume[i], deno[i]);
        if (l == 0) l = 1;
        nume[i] /= l;
        deno[i] /= l;
        if (deno[i] < 0) {
            deno[i] = 0-deno[i];
            nume[i] = 0-nume[i];
        }
    }
    LL n,d, l = gcd(deno[0], deno[1]), L;
    if (l == 0) l = 1;
    LL b1l = deno[0]/l, b2l = deno[1]/l;
    n = nume[0]*b2l+nume[1]*b1l;
    d = deno[0]*b2l;
    fpri('+', n, d);
    n -= (2*nume[1]*b1l);
    fpri('-', n, d);
    n = nume[0]*nume[1];
    d = deno[0]*deno[1];
    fpri('*', n, d);
    n = nume[0]*deno[1];
    d = deno[0]*nume[1];
    fpri('/', n, d);
    return 0;
}
