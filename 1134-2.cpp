#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> m;
int N, M;
int visit[10000];
int main()
{
    scanf("%d%d", &N, &M);
    m.resize(N);
    int a, b;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        m[a].push_back(i);
        m[b].push_back(i);
    }
    int Q, n, v, flag = 1;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &n);
        flag = 1;
        fill(visit, visit+M, 0);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &v);
            for (int k : m[v]) {
                visit[k] = 1;
            }
        }
        for (int j = 0; j < M; ++j) {
            if (visit[j] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
