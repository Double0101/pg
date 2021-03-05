#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
const int inf = 999999999;
vector<vector<int>> m(10000);
unordered_map<int, int> line;
bool visit[10000];
vector<int> path, tmppath;
int ts = inf, nstation = inf;

void dfs(int stn, int dst)
{
    if (tmppath.size() > nstation) return;
    tmppath.push_back(stn);
    visit[stn] = true;
    if (stn == dst && tmppath.size() <= nstation) {
        int tmpt = 0, pline = line[tmppath[0]*10000+tmppath[1]];
        for (int i = 2; i < tmppath.size(); ++i) {
            int l = line[tmppath[i]*10000+tmppath[i-1]];
            if (l != pline) ++tmpt;
            pline = l;
        }
        if ((tmppath.size() < nstation)
            || (tmppath.size() == nstation && tmpt < ts)) {
            path = tmppath;
            ts = tmpt;
            nstation = tmppath.size();
        }
    } else if (tmppath.size() < nstation) {
        for (int i : m[stn]) {
            if (visit[i] == false) {
                dfs(i, dst);
            }
        }
    }
    tmppath.pop_back();
    visit[stn] = false;
}

int main()
{
    scanf("%d", &N);
    int n, s, pre;
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d", &n, &pre);
        for (int j = 1; j < n; ++j) {
            scanf("%d", &s);
            line[pre*10000+s] = line[s*10000+pre] = i;
            m[pre].push_back(s);
            m[s].push_back(pre);
            pre = s;
        }
    }
    int Q, start, dest;
    scanf("%d", &Q);
    fill(visit, visit+10000, false);
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", &start, &dest);
        ts = nstation = inf;
        dfs(start, dest);
        int pline = line[path[0]*10000+path[1]];
        printf("%d\nTake Line#%d from %04d to ", nstation-1, pline, path[0]);
        for (int j = 2; j < nstation; ++j) {
            int l = line[path[j]*10000+path[j-1]];
            if (pline != l) {
                printf("%04d.\nTake Line#%d from %04d to ", path[j-1], l, path[j-1]);
                pline = l;
            }
        }
        printf("%04d.\n", path[nstation-1]);
    }
    return 0;
}
