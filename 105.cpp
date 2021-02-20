#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) { return a > b; }
int N, m, n;
int arr[10000];
int matric[100][100];
int index = 0;
int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    scanf("%d", &N);
    n = sqrt(N);
    while (N%n != 0) --n;
    m = N/n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", arr+index++);
            matric[i][j] = -1;
        }
    }
    sort(arr, arr+N, cmp);
    int d = 0, x=0, y=-1, nx, ny;
    for (int i = 0; i < N; ++i) {
        nx = x+direct[d][0];
        ny = y+direct[d][1];
        if (nx >= m || ny >= n || nx < 0 || ny < 0 || matric[nx][ny] != -1) {
            d = (d+1)%4;
            nx = x+direct[d][0];
            ny = y+direct[d][1];
        }
        matric[nx][ny] = arr[i];
        x = nx;
        y = ny;
    }
    for (int i = 0; i < m; ++i) {
        printf("%d", matric[i][0]);
        for (int j = 1; j < n; ++j) {
            printf(" %d", matric[i][j]);
        }
        printf("\n");
    }
    return 0;
}
