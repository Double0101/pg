#include <stdio.h>
#include <stdlib.h>

/* how much prime factor in n! */

int cal(int n, int p) {
    int ans = 0;
    while (n) {
        ans += (n/p);
        n /= p;
    }

    return ans;
}

/* calculate combinatorial number */
long long comb(int n, int m)
{
    if (m == 0 || m == n) return 1;
    return comb(n - 1, m) + comb(n - 1, m - 1);
}

int main()
{
    printf("%lld\n", comb(5, 2));
    printf("%d\n", cal(10, 2));
    return 0;
}