#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

vector<vector<int>> m;
int degree[1001];
int decp[1001];
int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    m.resize(N+1);
    int a, b;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        degree[b] += 1;
        m[a].push_back(b);
    }
    int Q, flag, nn = 0;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        flag = 0;
        for (int j = 1; j <= N; ++j) {
            decp[j] = degree[j];
        }
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &a);
            if (decp[a] != 0) flag = 1;
            for (int v : m[a]) {
                --decp[v];
            }
        }

        if (flag == 1) {
            if (nn++ != 0) printf(" ");
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}
