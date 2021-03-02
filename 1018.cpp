#include <cstdio>
#include <vector>

using namespace std;
const int inf = 999999999;
int capacity, nstation, ps, nroad, cnt = inf, bck = inf;
vector<int> curn;
vector<vector<pair<int, int>>> m;
vector<vector<int>> pre;
vector<int> tmppath, path;
void dfs(int r) {
    tmppath.push_back(r);
    if (r == 0) {
        int come = 0, back = 0;
        for (int i = tmppath.size()-2; i >= 0; --i) {
            int bn = curn[tmppath[i]]-capacity/2;
            if (bn >= 0) {
                back += bn;
            } else {
                if (back+bn > 0) back += bn;
                else {
                    come -= (back+bn);
                    back = 0;
                }
            }
        }
        if (come < cnt || (come == cnt && back < bck)) {
            cnt = come, bck = back;
            path = tmppath;
        }
    }
    for (int i : pre[r]) {
        dfs(i);
    }
    tmppath.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &capacity, &nstation, &ps, &nroad);
    curn.resize(nstation+1);
    m.resize(nstation+1);
    pre.resize(nstation+1);
    curn[0] = 0;
    for (int i = 1; i <= nstation; ++i) {
        scanf("%d", &(curn[i]));
    }
    int a, b, c;
    for (int i = 0; i < nroad; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        m[a].push_back(make_pair(b, c));
        m[b].push_back(make_pair(a, c));
    }
    vector<int> dis(nstation+1, inf);
    vector<bool> visit(nstation+1, false);
    dis[0] = 0;
    for (int i = 0; i <= nstation; ++i) {
        int stn = -1, md = inf;
        for (int j = 0; j <= nstation; ++j) {
            if (visit[j] == false && dis[j] < md) {
                stn = j;
                md = dis[j];
            }
        }
        if (stn == -1) break;
        visit[stn] = true;
        if (stn == ps) break;
        for (auto it : m[stn]) {
            if (visit[it.first] == false) {
                if (dis[it.first] > dis[stn]+it.second) {
                    dis[it.first] = dis[stn]+it.second;
                    pre[it.first].clear();
                }
                if (dis[it.first] == dis[stn]+it.second) {
                    pre[it.first].push_back(stn);
                }
            }
        }
    }
    dfs(ps);
    printf("%d ", cnt);
    for (int i = path.size()-1; i > 0 ; --i) {
        printf("%d->", path[i]);
    }
    printf("%d %d\n", path[0], bck);
    return 0;
}
