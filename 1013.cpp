#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int father[1000];
int Father(int s) {
    if (father[s] == 0) father[s] = s;
    if (father[s] == s) return s;
    int f = Father(father[s]);
    father[s] = f;
    return f;
}
void Union(int s1, int s2) {
    int f1 = Father(s1);
    int f2 = Father(s2);
    if (f1 != f2) {
        father[f2] = f1;
        Father(s2);
    }
}
vector<pair<int, int>> roads;
int N, M, K;
int main()
{
    scanf("%d%d%d", &N, &M, &K);
    roads.resize(M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &(roads[i].first), &(roads[i].second));
    }
    int city;
    for (int i = 0; i < K; ++i) {
        fill(father, father+1000, 0);
        scanf("%d", &city);
        for (int j = 0; j < M; ++j) {
            if (roads[j].first != city && roads[j].second != city) {
                Union(roads[j].first, roads[j].second);
            }
        }
        int connect = 0;
        for (int j = 1; j <= N; ++j) {
            if (Father(j) == j) ++connect;
        }
        printf("%d\n", connect-2);
    }
    return 0;
}
