#include <cstdio>
#include <queue>

using namespace std;

int m[60][1286][128];
int direct[6][3] = {{0, 0, 1}, {0, 0, -1},
                    {0, 1, 0}, {0, -1, 0},
                    {1, 0, 0}, {-1, 0, 0}};
bool visit[60][1286][128];
int M, N, L, T;

typedef struct Node {
    int l, m, n;
} node;

bool inrange1(int i, int j, int k) {
    return i >= 0 && i < L && j >= 0 && j < M && k >= 0 && k < N;
}
bool inrange2(node n) { return inrange1(n.l, n.m, n.n); }
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
    queue<node> q;
    int total = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                if (m[i][j][k] == 1 && visit[i][j][k] == false) {
                    node n;
                    n.l = i, n.m = j, n.n = k;
                    int count = 0;
                    q.push(n);
                    visit[i][j][k] = true;
                    while (!q.empty()) {
                        n = q.front();
                        q.pop();
                        ++count;
                        node tmp;
                        for (int l = 0; l < 6; ++l) {
                            tmp.l = n.l+direct[l][0];
                            tmp.m = n.m+direct[l][1];
                            tmp.n = n.n+direct[l][2];
                            if (inrange2(tmp)
                                && m[tmp.l][tmp.m][tmp.n] == 1
                                && visit[tmp.l][tmp.m][tmp.n] == false) {
                                visit[tmp.l][tmp.m][tmp.n] = true;
                                q.push(tmp);
                            }
                        }
                    }
                    if (count >= T) total += count;
                }
            }
        }
    }
    printf("%d\n", total);
    return 0;
}
