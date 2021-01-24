#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

typedef struct wayc {
    int dest;
    int distance, cost;
} wayc;

const int inf = 999999999;
vector<vector<wayc>> m(500);
vector<vector<int>> pre(500);
bool visit[500];
int dis[500];
int nc, wc, start, dest;
vector<int> temppath, path;
int cost = inf;

void dfs(int city)
{
    if (city == start) {
        int pc = start, c = 0;
        for (int i = temppath.size()-1; i >= 0; --i) {
            for (wayc w : m[pc]) {
                if (w.dest == temppath[i]) {
                    c += w.cost;
                    pc = temppath[i];
                    break;
                }
            }
        }
        if (c < cost) {
            cost = c;
            path = temppath;
        }
        return;
    }
    temppath.push_back(city);
    for (int pcity : pre[city]) {
        dfs(pcity);
    }
    temppath.pop_back();
    return;
}

int main()
{
    scanf("%d%d%d%d", &nc, &wc, &start, &dest);
    fill(dis, dis+nc, inf);
    fill(visit, visit+nc, false);
    for (int i = 0; i < wc; ++i) {
        int a, b, c, d;
        wayc w1, w2;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        w1.dest = b;
        w1.distance = c;
        w1.cost = d;
        w2.dest = a;
        w2.distance = c;
        w2.cost = d;
        m[a].push_back(w1);
        m[b].push_back(w2);
    }
    dis[start] = 0;
    for (int i = 0; i < 500; ++i) {
        int sc = -1, dc = inf;
        for (int j = 0; j < nc; ++j) {
            if (visit[j] == false && dis[j] < dc) {
                sc = j;
                dc = dis[j];
            }
        }
        if (sc == -1) break;
        visit[sc] = true;
        if (sc == dest) break;
        for (wayc w : m[sc]) {
            if (visit[w.dest] == true) continue;
            if (dis[w.dest] > dis[sc] + w.distance) {
                dis[w.dest] = dis[sc] + w.distance;
                pre[w.dest].clear();
            }
            if (dis[w.dest] == dis[sc] + w.distance)
                pre[w.dest].push_back(sc);
        }
    }

    dfs(dest);
    path.push_back(start);
    for (int i = path.size()-1; i >= 0; --i) {
        printf("%d ", path[i]);
    }
    printf("%d %d\n", dis[dest], cost);
    return 0;
}