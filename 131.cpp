#include <unordered_map>
#include <cstdio>
#include <vector>
#include <algorithm>

#define LEIDX(a, b) (a*10000+b)

using namespace std;

const int inf = 99999;
int N, sn, pre, s, Q, mtfc, msc;
int ori, dest;
unordered_map<int, int> line;
vector<vector<int>> nstation(10000);
vector<bool> visited(10000);
vector<int> path, tmppath;

void dfs(int station) {
    tmppath.push_back(station);
    visited[station] = true;
    if (station == dest) {
        if (tmppath.size() <= msc) {
            int l = line[LEIDX(tmppath[0], tmppath[1])], tl;
            int tfc = 0;
            int ps = tmppath[1];
            for (int i = 2; i < tmppath.size(); ++i) {
                tl = line[LEIDX(ps, tmppath[i])];
                if (tl != l) {
                    ++tfc;
                    l = tl;
                }
                ps = tmppath[i];
            }
            if (tmppath.size() < msc || tfc < mtfc) {
                path = tmppath;
                msc = tmppath.size();
                mtfc = tfc;
            }
        }
    }
    if (tmppath.size() < msc) {
        for (int ns : nstation[station]) {
            if (visited[ns] == false)
                dfs(ns);
        }
    }
    tmppath.pop_back();
    visited[station] = false;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &sn, &pre);
        for (int j = 1; j < sn; ++j) {
            scanf("%d", &s);
            line[LEIDX(pre, s)] = line[LEIDX(s, pre)] = i;
            nstation[pre].push_back(s);
            nstation[s].push_back(pre);
            pre = s;
        }
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", &ori, &dest);
        fill(visited.begin(), visited.end(), false);
        mtfc = msc = inf;
        dfs(ori);
        int ll = line[LEIDX(path[0], path[1])];
        int press = path[1];
        printf("%d\n", msc-1);
        printf("Take Line#%d from %04d", ll, ori);
        for (int j = 2; j < msc; ++j) {
            int l = line[LEIDX(press, path[j])];
            if (l != ll) {
                printf(" to %04d.\nTake Line#%d from %04d", press, l, press);
            }
            press = path[j];
            ll = l;
        }
        printf(" to %04d.\n", dest);
    }
    return 0;
}
