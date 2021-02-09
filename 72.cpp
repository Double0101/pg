#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int inf = 999999999;
int N, M, T, K, R;
int dis[1024];
bool visit[1024];
vector<vector<pair<int, int>>> mmap;

int mrc = -1, minc = -1, totr = inf;

void dijkstra(int ori) {
    fill(dis, dis+1024, inf);
    fill(visit, visit+1024, false);
    dis[ori] = 0;
    for (int i = 0; i < T; ++i) {
        int mc = -1, md = inf;
        for (int j = 1; j <= T; ++j) {
            if ((!visit[j]) && dis[j] < md) {
                mc = j;
                md = dis[j];
            }
        }
        if (mc == -1 || dis[mc] > R) return;
        visit[mc] = true;
        for (auto it : mmap[mc]) {
            if ((!visit[it.first]) && dis[it.first] > dis[mc] + it.second) {
                dis[it.first] = dis[mc] + it.second;
            }
        }
    }
}

int getindex(char *s) {
    int index = 0;
    int start = 0;
    if (s[0] == 'G') start = 1;
    while (s[start] != '\0') {
        index = index*10 + s[start] - '0';
        ++start;
    }
    if (s[0] == 'G') index += N;
    return index;
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &R);
    T = M+N;
    mmap.resize(T+1);
    char s1[10], s2[10];
    int i1, i2, tmpd;
    for (int i = 0; i < K; ++i) {
        scanf("%s %s %d", s1, s2, &tmpd);
        i1 = getindex(s1);
        i2 = getindex(s2);
        mmap[i1].push_back(make_pair(i2, tmpd));
        mmap[i2].push_back(make_pair(i1, tmpd));
    }
    for (int i = 1; i <= M; ++i) {
        dijkstra(N+i);
        int count = 0, mind = inf, totaldis = 0;
        for (int j = 1; j <= N; ++j) {
            if (dis[j] > R) break;
            count++;
            totaldis += dis[j];
            if (dis[j] < mind) mind = dis[j];
        }
        if (count < N) continue;
        if (minc < mind) {
            minc = mind;
            totr = totaldis;
            mrc = i;
        }
        if (minc == mind) {
            if(totr > totaldis) {
                totr = totaldis;
                mrc = i;
            }
        }
    }
    if (mrc == -1) printf("No Solution\n");
    else {
        printf("G%d\n", mrc);
        printf("%.01f %.01f\n", (float) minc, (totr*1.0)/N);
    }
    return 0;
}