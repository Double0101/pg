#include <cstdio>
#include <algorithm>

using namespace std;

int m[201][201];
int N, M;
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        fill(m[i], m[i]+201, -1);
    }
    int a, b, c, pre, start;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        m[a][b] = m[b][a] = c;
    }
    scanf("%d", &a);
    int mii = -1, min = 999999999;
    for (int i = 1; i <= a; ++i) {
        int visit[201] = {0};
        int total = 0, flag = 1;
        scanf("%d%d", &b, &start);
        pre = start;
        for (int j = 1; j < b; ++j) {
            scanf("%d", &c);
            visit[c] += 1;
            total += m[pre][c];
            if (m[pre][c] < 0) flag = 0;
            pre = c;
        }
        printf("Path %d: ", i);
        if (flag == 0) printf("NA (");
        else printf("%d (", total);
        int zn = 0, cn = 0;
        for (int j = 1; j <= N; ++j) {
            if (visit[j] == 0) ++zn;
            else cn += visit[j];
        }
        if (zn != 0 || flag == 0) printf("Not a TS cycle)\n");
        else {
            if (cn == N) printf("TS simple cycle)\n");
            else printf("TS cycle)\n");
            if (total < min) {
                min = total;
                mii = i;
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", mii, min);
    return 0;
}