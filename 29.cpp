#include <cstdio>
#include <algorithm>

using namespace std;

int ac, bc;
int as, bs;
long A[200000];
long B[200000];

int main()
{
    scanf("%d", &ac);
    for (int i = 0; i < ac; ++i) {
        scanf("%ld", A+i);
    }
    scanf("%d", &bc);
    for (int i = 0; i < bc; ++i) {
        scanf("%ld", B+i);
    }
    as = bs = 0;
    int n = (ac+bc-1)/2;
    int i = 0;
    while (i <= n) {
        if (as < ac && bs < bc) {
            if (A[as] < B[bs]) {
                ++as;
            } else {
                ++bs;
            }
        } else if (as < ac) {
            ++as;
        } else {
            ++bs;
        }
        ++i;
    }
    long m;
    if (as > 0 && bs > 0)
        m = A[as-1] > B[bs-1] ? A[as-1] : B[bs-1];
    else if (as > 0)
        m = A[as-1];
    else
        m = B[bs-1];
    printf("%ld\n", m);
    return 0;
}