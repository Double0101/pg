#include <cstdio>
#include <vector>

using namespace std;

const int inf = 999999999;
int capacity, hlf, nstation, ps, nroad, cb = inf, bb = inf;
vector<vector<pair<int, int>>> m;
vector<int> nbike;
vector<vector<int>> pre;
vector<bool> visit;
vector<int> dis, path, tmppath;

void dfs(int r)
{
    tmppath.push_back(r);
    if (r == 0) {
        int come = 0, back = 0;
        for (int i = tmppath.size()-2; i >= 0; --i) {
            if (nbike[tmppath[i]] >= hlf) {
                back += (nbike[tmppath[i]]-hlf);
            } else {
                if (hlf - nbike[tmppath[i]] >= back) {
                    come += (hlf-nbike[tmppath[i]]-back);
                    back = 0;
                } else {
                    back -= (hlf-nbike[tmppath[i]]);
                }
            }
        }
        if (come < cb || (come == cb && back < bb)) {
            path = tmppath;
            cb = come, bb = back;
        }
    }
    for (int i : pre[r])
        dfs(i);
    tmppath.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &capacity, &nstation, &ps, &nroad);
    hlf = capacity/2;
    m.resize(nstation+1);
    nbike.resize(nstation+1);
    for (int i = 1; i <= nstation; ++i) {
        scanf("%d", &(nbike[i]));
    }
    nbike[0] = 0;
    int a, b, c;
    for (int i = 0; i < nroad; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        m[a].emplace_back(b, c);
        m[b].emplace_back(a, c);
    }
    pre.resize(nstation+1);
    visit.resize(nstation+1, false);
    dis.resize(nstation+1, inf);
    dis[0] = 0;
    for (int i = 0; i <= nstation; ++i) {
        int stn = -1, min = inf;
        for (int j = 0; j <= nstation; ++j) {
            if (visit[j] == false && dis[j] < min) {
                stn = j;
                min = dis[j];
            }
        }
        if (stn == -1) break;
        visit[stn] = true;
        if (stn == ps) break;
        for (auto it : m[stn]) {
            if (visit[it.first] == false) {
                if (dis[it.first] > dis[stn] + it.second) {
                    dis[it.first] = dis[stn] + it.second;
                    pre[it.first].clear();
                }
                if (dis[it.first] == dis[stn] + it.second) {
                    pre[it.first].push_back(stn);
                }
            }
        }
    }
    dfs(ps);
    printf("%d 0", cb);
    for (int i = path.size()-2; i >= 0; --i) {
        printf("->%d", path[i]);
    }
    printf(" %d\n", bb);
    return 0;
}
