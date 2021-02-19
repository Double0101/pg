#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int N, max = 0, maxstart, tmpstart;
    scanf("%d", &N);
    int maxn = sqrt(N)+1;
    for (int i = 2; i <= maxn; ++i) {
        if (N%i != 0) continue;
        int n = N, num = 0;
        tmpstart = i;
        for (int j = i; j <= n && n%j == 0; ++j) {
            ++num;
            n /= j;
        }
        if (num > max) {
            max = num;
            maxstart = tmpstart;
        }
    }
    if (max == 0) {
        max = 1;
        maxstart = N;
    }
    printf("%d\n", max);
    printf("%d", maxstart);
    for (int i = 1; i < max; ++i) {
        printf("*%d", maxstart+i);
    }
    printf("\n");
    return 0;
}
