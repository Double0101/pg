#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int visit[10001] = {0};
vector<vector<int>> m;
int N, M;
int main()
{
    scanf("%d%d", &N, &M);
    m.resize(N);
    int a, b, Q;
    for (int i = 1; i <= M; ++i) {
        scanf("%d%d", &a, &b);
        m[a].push_back(i);
        m[b].push_back(i);
    }
    scanf("%d", &Q);
    int vc, v, flag;
    for (int i = 0; i < Q; ++i) {
        fill(visit, visit+M+1, 0);
        scanf("%d", &vc);
        for (int j = 0; j < vc; ++j) {
            scanf("%d", &v);
            for (int k : m[v]) {
                visit[k] = 1;
            }
        }
        flag = 1;
        for (int j = 1; j <= M; ++j) {
            if (visit[j] == 0) flag = 0;
        }
        if (flag == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
