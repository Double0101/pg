#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long LL;

using namespace std;
vector<LL> nns;
LL N, p;
int main()
{
    scanf("%lld%lld", &N, &p);
    nns.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &(nns[i]));
    }
    sort(nns.begin(), nns.end());
    LL max = 0;
    for (LL i = 0; i < N-max; ++i) {
        LL mm = nns[i]*p;
        LL j = i+max;
        while (j < N && nns[j] <= mm) ++j;
        if (j-i > max) max = j-i;
    }
    printf("%lld\n", max);
    return 0;
}
