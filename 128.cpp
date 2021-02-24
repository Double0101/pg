#include <cstdio>
#include <algorithm>

using namespace std;

int row[1001] = {0};
int diag1[2001] = {0};
int diag2[2001] = {0};
int main()
{
    int K, N, flag, a;
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &N);
        flag = 1;
        fill(row, row+N+1, 0);
        fill(diag1, diag1+N+N+1, 0);
        fill(diag2, diag2+N+N+1, 0);
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &a);
            if (row[a] == 1) flag = 0;
            row[a] = 1;
            if (diag1[a+j] == 1) flag = 0;
            diag1[a+j] = 1;
            if (diag2[a-j+N] == 1) flag = 0;
            diag2[a-j+N] = 1;
        }
        if (flag == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}