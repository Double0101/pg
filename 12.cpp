#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int, int>> roads;
int s[1000] = {0};

int N, M, K;

int Find(int p)
{
    if (s[p] == p) return p;
    int fp = p;
    while (s[fp] != fp) {
        fp = s[fp];
    }
    while (p != s[p]) {
        int z = p;
        p = s[p];
        s[z] = fp;
    }
    return fp;
}

void Union(int a, int b)
{
    int a1 = Find(a);
    int b1 = Find(b);
    if (a1 != b1) {
        s[b1] = a1;
    }
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        roads.push_back(make_pair(a, b));
    }

    int cc;
    for (int i = 0; i < K; ++i) {
        scanf("%d", &cc);
        memset(s, 0, sizeof(int)*1000);
        for (int i = 1; i <= N; ++i) {
            s[i] = i;
        }
        for (int j = 0; j < roads.size(); ++j) {
            if (roads[j].first != cc && roads[j].second != cc)
                Union(roads[j].first, roads[j].second);
        }
        int sum = 0;
        for (int j = 1; j <= N; ++j) {
            if (s[j] == j) ++sum;
        }
        printf("%d\n", sum - 2);
    }

    return 0;
}