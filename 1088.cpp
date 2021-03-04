#include <cstdio>

typedef long long LL;

LL gcd(LL l1, LL l2)
{
    if (l2 == 0 || l1%l2 == 0) return l2;
    return gcd(l2, l1%l2);
}

void simply(LL &l1, LL &l2)
{
    LL aaa = gcd(l1, l2);
    if (aaa != 0) {
        l1 /= aaa;
        l2 /= aaa;
    }
    if (l2 < 0) {
        l2 = 0-l2;
        l1 = 0-l1;
    }
}

void add(LL &num1, LL &den1, LL &num2, LL &den2, LL &num3, LL &den3)
{
    LL l = gcd(den1, den2);
    den3 = den1/l*den2;
    num3 = den2/l*num1 + den1/l*num2;
    simply(num3, den3);
}

void multiple(LL &num1, LL &den1, LL &num2, LL &den2, LL &num3, LL &den3)
{
    if (den2 == 0){
        num3 = 0, den3 = 0;
        return;
    }
    if (num1 == 0 || num2 == 0) {
        num3 = 0, den3 = 1;
        return;
    }
    num3 = num1*num2;
    den3 = den1*den2;
    simply(num3, den3);
}
void print(LL num, LL den)
{
    if (den == 0) {
        printf("Inf");
        return;
    }
    if (num < 0) printf("(");
    LL n1 = num/den, n2 = num%den;
    n2 = n2 < 0 ? 0-n2 : n2;
    if (n2 == 0) printf("%lld", n1);
    else if (n1 == 0) printf("%lld/%lld", num, den);
    else printf("%lld %lld/%lld", n1, n2, den);
    if (num < 0) printf(")");
}

int main()
{
    LL a1, a2, b1, b2, c1, c2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    simply(a1, b1);
    simply(a2, b2);
    add(a1, b1, a2, b2, c1, c2);
    print(a1, b1);
    printf(" + ");
    print(a2, b2);
    printf(" = ");
    print(c1, c2);
    printf("\n");
    a2 = 0-a2;
    add(a1, b1, a2, b2, c1, c2);
    a2 = 0-a2;
    print(a1, b1);
    printf(" - ");
    print(a2, b2);
    printf(" = ");
    print(c1, c2);
    printf("\n");
    multiple(a1, b1, a2, b2, c1, c2);
    print(a1, b1);
    printf(" * ");
    print(a2, b2);
    printf(" = ");
    print(c1, c2);
    printf("\n");
    multiple(a1, b1, b2, a2, c1, c2);
    print(a1, b1);
    printf(" / ");
    print(a2, b2);
    printf(" = ");
    print(c1, c2);
    printf("\n");
    return 0;
}
