#include <cstdio>
#include <cstring>
#include <cstdlib>


int **dp;
int *w;
int *v;

int volume, cc;

int main()
{
    scanf("%d%d", &cc, &volume);
    w = (int*) malloc(sizeof(int) * cc);
    v = (int*) malloc(sizeof(int) * cc);
    dp = (int**) malloc(sizeof(int*) * cc);
    for (int i = 0; i < cc; ++i) {
        dp[i] = (int*) malloc(sizeof(int) * (volume + 1));
        int *d = dp[i];
        memset(d, 0, sizeof(int) * (volume + 1));
    }

    for (int k = 0; k < cc; ++k) {
        scanf("%d", &w[k]);
    }
    for (int k = 0; k < cc; ++k) {
        scanf("%d", &v[k]);
    }

    for (int j = 0; j < cc; ++j) {
        for (int i = 1; i <= volume; ++i) {
            if (i - w[j] >= 0) {
                dp[j][i] = dp[j][i-w[j]] + v[j];
            }
            if (j > 0 && dp[j-1][i] > dp[j][i]) {
                dp[j][i] = dp[j-1][i];
            }
        }
    }

    for (int l = 0; l <= volume; ++l) {
        printf("%d ", dp[cc-1][l]);
    }

    return 0;
}