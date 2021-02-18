#include <cstdio>
#include <queue>

using namespace std;

int M, N, num, threshold;
int slices[60][1286][128];
bool visited[60][1286][128];
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};

typedef struct Cell {
    int x, y, z;
} cell;
inline
bool inr(int x, int y, int z)
{
    return x >= 0 && x < num && y >= 0 && y < M && z >= 0 && z < N;
}
inline
bool inrange(cell c) { return inr(c.x, c.y, c.z); }

int main()
{
    scanf("%d%d%d%d", &M, &N, &num, &threshold);
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                scanf("%d", &(slices[i][j][k]));
                visited[i][j][k] = false;
            }
        }
    }

    queue<cell> cq;
    cell tmp, tt;
    int total = 0;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                int cc = 0;
                if (inr(i, j, k) && (slices[i][j][k] == 1) && (!visited[i][j][k])) {
                    tmp.x = i, tmp.y = j, tmp.z = k;
                    visited[tmp.x][tmp.y][tmp.z] = true;
                    cq.push(tmp);
                    while (!cq.empty()) {
                        tmp = cq.front();
                        cq.pop();
                        ++cc;
                        for (int l = 0; l < 6; ++l) {
                            tt.x = tmp.x+X[l];
                            tt.y = tmp.y+Y[l];
                            tt.z = tmp.z+Z[l];
                            if (inrange(tt)
                                && slices[tt.x][tt.y][tt.z] == 1
                                && !visited[tt.x][tt.y][tt.z]) {
                                visited[tt.x][tt.y][tt.z] = true;
                                cq.push(tt);
                            }
                        }
                    }
                    if (cc >= threshold) total+=cc;
                }
            }
        }
    }
    printf("%d\n", total);
    return 0;
}
