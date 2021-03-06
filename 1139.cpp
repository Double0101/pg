#include <vector>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool gender[10000];
vector<int> friends[10000];
int N, M;
vector<pair<int, int>> ans;
unordered_map<int, int> isf;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

int main()
{
    scanf("%d%d", &N, &M);
    int a, b;
    char ac[10], bc[10];
    fill(gender, gender+10000, false);
    for (int i = 0; i < M; ++i) {
        scanf("%s %s", ac, bc);
        sscanf(ac, "%d", &a);
        sscanf(bc, "%d", &b);
        if (ac[0] == '-') a = 0-a, gender[a] = true;
        if (bc[0] == '-') b = 0-b, gender[b] = true;
        isf[a*10000+b] = isf[b*10000+a] = 1;
        if (gender[a] == gender[b]) {
            friends[a].push_back(b);
            friends[b].push_back(a);
        }
    }
    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        ans.clear();
        scanf("%d%d", &a, &b);
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        for (int j : friends[a]) {
            for (int k : friends[b]) {
                if (isf[j*10000 + k] == 1 && j != b && k != a)
                    ans.emplace_back(j, k);
            }
        }
        printf("%d\n", ans.size());
        sort(ans.begin(), ans.end(), cmp);
        for (auto it : ans) {
            printf("%04d %04d\n", it.first, it.second);
        }
    }
    return 0;
}
