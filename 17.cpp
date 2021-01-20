#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int inf = 99999999;
vector<vector<int>> pre(510);
vector<vector<pair<int, int>>> m(510);
vector<int> waydis(510, inf);
vector<int> bike(510, 0);
vector<bool> visit(510, 0);
vector<int>  path, temppath;
int mincome = inf, minback = inf;

int capacity, sc, ps, M, level;

void dfs(int v)
{
    temppath.push_back(v);
    if (v == 0) {
        int come = 0, back = 0;
        for (int i = temppath.size()-1; i >= 0; --i) {
            int id = temppath[i];
            if (bike[id] > 0) {
                back += bike[id];
            } else {
                if (back + bike[id] > 0) {
                    back += bike[id];
                } else {
                    come += (-bike[id]-back);
                    back = 0;
                }
            }
        }
        if (come < mincome
            || (come == mincome && back < minback)) {
            minback = back;
            mincome = come;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); ++i) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main()
{
    scanf("%d%d%d%d", &capacity, &sc, &ps, &M);
    level = capacity/2;
    for (int i = 1; i <= sc; ++i) {
        scanf("%d", &bike[i]);
        bike[i] = bike[i] - level;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        m[a].push_back(make_pair(b, c));
        m[b].push_back(make_pair(a, c));
    }

    waydis[0] = 0;
    pre[0].push_back(0);

    for (int i = 0; i <= sc; ++i) {
        int station = -1, minn = inf;
        for (int j = 0; j < sc; ++j) {
            if (visit[j] == 0 && waydis[j] < minn) {
                station = j;
                minn = waydis[station];
            }
        }
        if (station == ps || station == -1) break;
        visit[station] = 1;
        for (auto it : m[station]) {
            if (visit[it.first] == 0) {
                if (waydis[it.first] == waydis[station] + it.second) {
                    pre[it.first].push_back(station);
                } else if (waydis[it.first] > waydis[station] + it.second) {
                    waydis[it.first] = waydis[station] + it.second;
                    pre[it.first].clear();
                    pre[it.first].push_back(station);
                }
            }
        }
    }

    dfs(ps);
    printf("%d 0", mincome);
    for (int i = path.size()-2; i >= 0; --i) {
        printf("->%d", path[i]);
    }
    printf(" %d\n", minback);

    return 0;
}