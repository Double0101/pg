#include <cstdio>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL l1, LL l2) {
    if (l1%l2 == 0) return l2;
    return gcd(l2, l1%l2);
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<LL> numerator(N);
    vector<LL> denominator(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld/%lld", &numerator[i], &denominator[i]);
        LL l = gcd(numerator[i], denominator[i]);
        if (l == 0) continue;
        numerator[i] /= l;
        denominator[i] /= l;
    }
    LL num = 0, den = 1, l1, l2;
    for (int i = 0; i < N; ++i) {
        LL l = gcd(denominator[i], den);
        l1 = l2 = 1;
        if (l != 0) {
            l1 = denominator[i]/l;
            l2 = den/l;
        }
        den *= l1;
        num = num*l1 + numerator[i]*l2;
        l = gcd(num, den);
        if (l == 0) continue;
        den /= l;
        num /= l;
    }
    if (den < 0) {
        den = 0-den;
        num = 0-num;
    }
    l1 = num/den;
    l2 = num%den;
    if (l1==0 && l2==0) printf("0\n");
    else if (l1!=0 && l2==0) printf("%lld\n", l1);
    else if (l1==0) printf("%lld/%lld\n", l2, den);
    else printf("%lld %lld/%lld\n", l1, l2, den);
    return 0;
}
