#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> roads(N+1);
    roads[0] = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &roads[i]);
        roads[i] += roads[i-1];
    }
    int T;
    scanf("%d", &T);
    int total = roads[N];
    for (int i = 0; i < T; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        int l = (total+roads[a-1]-roads[b-1])%total;
        l = l > (total-l) ? total-l : l;
        printf("%d\n", l);
    }
    return 0;
}