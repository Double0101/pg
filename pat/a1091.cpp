#include <cstdio>
#include <queue>

using namespace std;

struct node {
    int x, y, z;
} NODE;

bool visited[1290][130][61] = {false};
int brain[1290][130][61];
int M, N, L, T;

int directX[6] = {0, 0, 0, 0, 1, -1};
int directY[6] = {0, 0, 1, -1, 0, 0};
int directZ[6] = {1, -1, 0, 0, 0, 0};

bool judge(int x, int y, int z)
{
    if (x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0) return false;
    return !(brain[x][y][z] == 0 || visited[x][y][z]);
}

int BFS(int x, int y, int z)
{
    int total = 0;
    queue<node> Q;
    NODE.x = x, NODE.y = y, NODE.z = z;
    Q.push(NODE);
    visited[x][y][z] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        ++total;
        for (int i = 0; i < 6; ++i) {
            int nX = top.x + directX[i];
            int nY = top.y + directY[i];
            int nZ = top.z + directZ[i];
            if (judge(nX, nY, nZ)) {
                NODE.x = nX, NODE.y = nY, NODE.z = nZ;
                Q.push(NODE);
                visited[nX][nY][nZ] = true;
            }
        }
    }
    if (total >= T) return total;
    else return 0;
}

int main()
{
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                scanf("%d", &brain[j][k][i]);
            }
        }
    }
    int ans = 0;
    for (int z = 0; z < L; ++z) {
        for (int x = 0; x < M; ++x) {
            for (int y = 0; y < N; ++y) {
                if (brain[x][y][z] == 1 && !visited[x][y][z]) {
                    ans += BFS(x, y, z);
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
