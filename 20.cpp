#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int father[10001];
int dis[10001];
bool visit[10001];
vector<vector<int>> m(10001);
int N;
set<int> startset1, startset2;

int Father(int a)
{
    int fa = father[a];
    if (fa == a) return a;
    while (fa != father[fa]) fa = father[fa];

    int aa = a;
    while (father[aa] != aa) {
        int temp = father[aa];
        father[aa] = fa;
        aa = temp;
    }
    return fa;
}

void Union(int a, int b)
{
    int fa = Father(a), fb = Father(b);
    if (fa == fb) return;
    father[fb] = fa;
}

void dijkstra(int start, set<int> &ss)
{
    fill(dis+1, dis+N+1, N);
    fill(visit, visit+N+1, 0);
    dis[start] = 0;
    for (int i = 0; i < N; ++i) {
        int ms = 0, md = N;
        for (int j = 1; j <= N; ++j) {
            if (visit[j] == 0 && dis[j] < md) {
                ms = j, md = dis[j];
            }
        }
        if (ms == 0) break;
        visit[ms] = 1;
        for (int k : m[ms]) {
            if (visit[k] == 0 && dis[k] > dis[ms] + 1) {
                dis[k] = dis[ms] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= N; ++i) {
        if (dis[i] == max) ss.insert(i);
        else if (dis[i] > max) {
            max = dis[i];
            ss.clear();
            ss.insert(i);
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        father[i] = i;
    }
    for (int i = 1; i < N; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        Union(a, b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int compoonent = 0;
    for (int i = 1; i <= N; ++i) {
        if (Father(i) == i) ++compoonent;
    }
    if (compoonent != 1) {
        printf("Error: %d components\n", compoonent);
        return 0;
    }
    dijkstra(1, startset1);
    auto it = startset1.begin();
    dijkstra(*it, startset2);
    startset1.insert(startset2.begin(), startset2.end());
    for (int i : startset1) {
        printf("%d\n", i);
    }

    return 0;
}