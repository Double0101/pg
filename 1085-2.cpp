#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;
vector<int> vs;
LL N, p;
int main()
{
    scanf("%lld%lld", &N, &p);
    vs.resize(N);
    for (LL i = 0; i < N; ++i) {
        scanf("%d", &(vs[i]));
    }
    sort(vs.begin(), vs.end());
     LL max = 0, bound;
    for (LL i = 0; i < N-max; ++i) {
        bound = vs[i]*p;
        LL j = i+max;
        while (j < N && vs[j] <= bound) ++j;
        if (j-i > max) max = j-i;
    }
    printf("%lld\n", max);
    return 0;
}
