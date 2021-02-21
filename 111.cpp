#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Road {
    int cost[2];
} road;

const int inf = 999999999;
int N, M, ori, dest, factor;
char label[2][10] = {"Distance", "Time"};
vector<int> result[2];
vector<bool> visit;
vector<int> cost[2];
int rcost[2];
vector<int> pre;
vector<road> roads;
vector<vector<pair<int, int>>> map;

void dijkstra() {
    fill(pre.begin(), pre.end(), -1);
    fill(visit.begin(), visit.end(), false);
    fill(cost[factor].begin(), cost[factor].end(), inf);
    cost[factor][ori] = 0;
    for (int i = 0; i < N; ++i) {
        int sc = -1, min = inf;
        for (int j = 0; j < N; ++j) {
            if (visit[j] == false && cost[factor][j] < min) {
                min = cost[factor][j];
                sc = j;
            }
        }
        if (sc == -1) return;
        visit[sc] = true;
        for (auto it : map[sc]) {
            if (visit[it.first] == false) {
                if (cost[factor][it.first] > cost[factor][sc] + roads[it.second].cost[factor]) {
                    cost[factor][it.first] = cost[factor][sc]+roads[it.second].cost[factor];
                    pre[it.first] = sc;
                    if (factor == 1) {
                        cost[0][it.first] = cost[0][sc]+roads[it.second].cost[0];
                    }
                }
                else if (factor == 1
                    && cost[factor][it.first] == cost[factor][sc] + roads[it.second].cost[factor]
                    && cost[0][it.first] > cost[0][sc]+roads[it.second].cost[0]) {
                    pre[it.first] = sc;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    roads.resize(M);
    map.resize(N);
    int ca, cb, ow, l, t;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d%d%d", &ca, &cb, &ow, &l, &t);
        roads[i].cost[0] = l, roads[i].cost[1] = t;
        map[ca].push_back(make_pair(cb, i));
        if (ow == 0)
            map[cb].push_back(make_pair(ca, i));
    }
    scanf("%d%d", &ori, &dest);
    visit.resize(N);
    cost[0].resize(N);
    cost[1].resize(N);
    pre.resize(N);
    int oc;
    for (factor = 0; factor < 2; ++factor) {
        dijkstra();
        oc = dest;
        rcost[factor] = cost[factor][dest];
        while (oc != -1) {
            result[factor].push_back(oc);
            oc = pre[oc];
        }
    }
    for (int j = 0; j < 2; ++j) {
        printf("%s = %d", label[j], rcost[j]);
        if (j == 0 && result[0] == result[1]) {
            printf("; ");
            continue;
        }
        else printf(": ");
        for (int i = result[j].size()-1; i > 0; --i) {
            printf("%d -> ", result[j][i]);
        }
        printf("%d\n", result[j][0]);
    }
    return 0;
}
