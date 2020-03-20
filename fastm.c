#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

LL binaryPow(LL a, LL b, LL m)
{
    if (b == 0) return 1;
    if (b % 2 == 1) {
        return a * binaryPow(a, b - 1, m) % m;
    }
    
    else {
        LL mul = binaryPow(a, b/2, m); 
        return mul * mul % m;
    }
}

int main()
{
    printf("%lld\n", binaryPow(2, 10, 5));
    return 0;
}