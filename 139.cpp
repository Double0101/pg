#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define IDX(a) (a < 0 ? -a : a)

using namespace std;

int indx[10000];
int visit[10000] = {0};
int N, M, Q, num = 0;
vector<vector<int>> relations;

vector<pair<int, int>> rs;
vector<int> tmp;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (IDX(p1.first) == IDX(p2.first)) return IDX(p1.second) < IDX(p2.second);
    return IDX(p1.first) < IDX(p2.first);
}
void dfs(int ori, int dst, int n)
{
    if (tmp.size() == 3 && n != dst) return;
    if (tmp.size() == 3 && n == dst) {
        rs.emplace_back(tmp[1], tmp[2]);
        return;
    }
    visit[IDX(n)] = 1;
    tmp.push_back(n);
    int gender = ori < 0 ? -1 : 1;
    int idx = indx[IDX(n)];
    if (ori != n) gender = dst < 0 ? -1 : 1;
    for (int i = 0; idx != -1 && i < relations[idx].size(); ++i) {
        if (visit[IDX(relations[idx][i])] == 0 && relations[idx][i]*gender > 0) {
            dfs(ori, dst, relations[idx][i]);
        }
    }
    visit[IDX(n)] = 0;
    tmp.pop_back();
}

int main()
{
    scanf("%d%d", &N, &M);
    fill(indx, indx + 10000, -1);
    relations.resize(N);
    int a, b, ia, ib;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        if (indx[IDX(a)] == -1) indx[IDX(a)] = num++;
        if (indx[IDX(b)] == -1) indx[IDX(b)] = num++;
        ia = indx[IDX(a)], ib = indx[IDX(b)];
        relations[ia].push_back(b);
        relations[ib].push_back(a);
    }
    scanf("%d", &Q);
    fill(visit, visit+10000, 0);
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", &a, &b);
        rs.clear();
        dfs(a, b, a);
        sort(rs.begin(), rs.end(), cmp);
        printf("%d\n", rs.size());
        for (int j = 0; j < rs.size(); ++j) {
            printf("%d %d\n", IDX(rs[j].first), IDX(rs[j].second));
        }
    }
    return 0;
}
