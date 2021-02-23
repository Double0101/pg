#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    vector<vector<int>> map(N+1);
    for (int i = 0; i <= N; ++i) {
        map[i].resize(N+1, 0);
    }
    int v1, v2;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &v1, &v2);
        map[v1][v2] = map[v2][v1] = 1;
    }
    int Q, n, first, pre, pv, flag;
    scanf("%d", &Q);
    vector<int> visit(N+1, 0);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &n);
        if (n == 0) {
            printf("NO\n");
            continue;
        }
        flag = 1;
        scanf("%d", &first);
        pre = first;
        fill(visit.begin(), visit.end(), 0);
        for (int j = 1; j < n; ++j) {
            scanf("%d", &pv);
            if (map[pre][pv] == 0) flag = 0;
            if (visit[pv] == 1) flag = 0;
            visit[pv] = 1;
            pre = pv;
        }
        if (n != N+1 || flag == 0) {
            printf("NO\n");
            continue;
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
