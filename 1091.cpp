#include <cstdio>

int direct[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 0, 1},
                    {0, 0, -1}, {0, 1, 0}, {0, -1, 0}};

int M, N, L, T;
int m[60][1286][128];
bool visit[60][1286][128];

void dfs(int s, int mm, int n, int &count)
{
    if (s >= 0 && s < L && mm >= 0
        && mm < M && n >= 0 && n < N
        && m[s][mm][n] == 1 && visit[s][mm][n] == false) {
        ++count;
        visit[s][mm][n] = true;
        for (int i = 0; i < 6; ++i) {
            dfs(s+direct[i][0], mm + direct[i][1], n + direct[i][2], count);
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                scanf("%d", &(m[i][j][k]));
                visit[i][j][k] = false;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                int count = 0;
                dfs(i, j, k, count);
                if (count >= T) {
                    total += count;
                }
            }
        }
    }
    printf("%d\n", total);
    return 0;
}
