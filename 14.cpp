#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


bool isPrime[100000];

int reverse(int num, int radix) {
    int rn[32] = {0};
    int tar = num;
    int res = 0;
    int i = 0;
    int r = radix;
    while (tar != 0) {
        int b = tar%r;
        rn[i++] = b*radix/r;
        tar -= b;
        r *= radix;
    }
    r = 1;
    for (--i; i >= 0 ; --i) {
        res += (rn[i]*r);
        r *= radix;
    }
    return res;
}

int main()
{
    fill(isPrime, isPrime + 100000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 100000; ++i) {
        if (isPrime[i] == true) {
            for (int j = 2*i; j < 100000; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int number, radix;
    scanf("%d", &number);
    while (number >= 0) {
        scanf("%d", &radix);
        if (isPrime[number] && isPrime[reverse(number, radix)])
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d", &number);
    }

    return 0;
}