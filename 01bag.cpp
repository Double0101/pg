#include <cstdio>
#include <cstdlib>
#include <cstring>

int volume;
int c;
int *w, *v;

int *dp;

int main()
{
    scanf("%d%d", &c, &volume);
    dp = (int*) malloc(sizeof(int) * (volume+1));
    memset(dp, 0, volume);
    w = (int*) malloc(sizeof(int) * c);
    v = (int*) malloc(sizeof(int) * c);

    for (int i = 0; i < c; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < c; ++i) {
        scanf("%d", &v[i]);
    }

    for (int j = 0; j < c; ++j) {
        for (int i = volume; i >= 0; --i) {
            if (i - w[j] >= 0) {
                if (dp[i-w[j]] + v[j] > dp[i]) {
                    dp[i] = dp[i-w[j]] + v[j];
                }
            }
        }
    }

    for (int k = 0; k <= volume; ++k) {
        printf("%d ", dp[k]);
    }
    printf("\n");

    return 0;
}