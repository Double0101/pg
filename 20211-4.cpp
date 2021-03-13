#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 999999999;
int m[201][201];
int dis[201][201];
int N, M;
bool visit[201];
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; ++i) {
        fill(m[i], m[i]+N+1, inf);
        fill(dis[i], dis[i]+N+1, inf);
    }
    int a, b, c;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        m[a][b] = m[b][a] = c;
    }
    for (int i = 0; i <= N; ++i) {
        fill(visit, visit+201, false);
        dis[i][i] = 0;
        for (int k = 0; k <= N; ++k) {
            int city = -1, min = inf;
            for (int j = 0; j <= N; ++j) {
                if (!visit[j] && dis[i][j] < min) {
                    city = j;
                    min = dis[i][j];
                }
            }
            if (city == -1) break;
            visit[city] = true;
            for (int j = 0; j <= N; ++j) {
                if (!visit[j] && dis[i][city] + m[city][j] < dis[i][j]) {
                    dis[i][j] = dis[i][city] + m[city][j];
                }
            }
        }
    }
    fill(visit, visit+201, false);
    int city = 0;
    printf("0");
    int total = 0, cnt = 0;
    while (city != -1) {
        visit[city] = true;
        int c = -1, min = inf;
        for (int i = 0; i <= N; ++i) {
            if (visit[i] == false && dis[city][i] < min) {
                c = i;
                min = dis[city][i];
            }
        }
        if (c != -1) {
            ++cnt;
            printf(" %d", c);
            total += dis[city][c];
        }
        city = c;
    }
    printf("\n");
    if (cnt == N) printf("%d\n", total);
    else {
        int num = 0;
        for (int i = 0; i <= N; ++i) {
            if (dis[0][i] == inf) {
                if (num++ != 0) printf(" ");
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}
