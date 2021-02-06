#include <cstdio>
#include <cmath>
#include <vector>

typedef long int LL;

using namespace std;

int main()
{
    LL N;
    scanf("%ld", &N);
    vector<int> ptable(50011, 0);
    ptable[0] = -1;
    ptable[1] = -1;
    for (int i = 2; i <= sqrt(50010.0); ++i) {
        if (ptable[i] == -1) continue;
        for (int j = i+i; j <= 50010; j += i) {
            ptable[j] = -1;
        }
    }

    LL dest = N;
    for (int i = 2; i <= 50010; ++i) {
        if (ptable[i] == -1) continue;
        while (dest%i == 0) {
            ++ptable[i];
            dest /= i;
        }
    }
    printf("%ld=", N);
    if (N == 1) {
        printf("1\n");
        return 0;
    }
    int e = 0;
    while (ptable[e] < 1) ++e;
    if (ptable[e] == 1) printf("%d", e);
    else printf("%d^%d", e, ptable[e]);
    for (++e; e <= 50010 ; ++e) {
        if (ptable[e] < 1) continue;
        if (ptable[e] == 1) printf("*%d", e);
        else printf("*%d^%d", e, ptable[e]);
    }
    if (dest != 1) printf("*%ld", dest);
    printf("\n");

    return 0;
}
