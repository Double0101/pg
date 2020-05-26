#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXL 100

char S[MAXL];
int **dp;
int sl;

int main()
{
    gets(S);
    int ans = 1;
    sl = strlen(S);
    dp = (int**) malloc(sizeof(int*) * (sl));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < sl; ++i) {
        dp[i] = (int*) malloc(sizeof(int) * (sl));
        dp[i][i] = 1;
    }
    for (int j = 0; j < sl; ++j) {
        if (S[j] == S[j+1]) {
            dp[j][j+1] = 1;
            ans = 2;
        }
    }
    for (int L = 3; L <= sl; ++L) {
        for (int i = 0; i + L - 1 < sl; ++i) {
            int j = i + L - 1;
            if (S[i] == S[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}