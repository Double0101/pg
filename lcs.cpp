#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXL 100

char SA[MAXL];
char SB[MAXL];

int **dp;

int main()
{
    gets(SA + 1);
    gets(SB + 1);
    int la, lb;
    la = strlen(SA + 1);
    lb = strlen(SB + 1);

    dp = (int**) malloc(sizeof(int*) * (la+1));
    for (int i = 0; i < la+1; ++i) {
        dp[i] = (int*) malloc(sizeof(int) * (lb+1));
        dp[i][0] = 0;
    }
    for (int j = 0; j < lb+1; ++j) {
        dp[0][j] = 0;
    }

    for (int k = 1; k < la + 1; ++k) {
        for (int i = 0; i < lb + 1; ++i) {
            if (SA[k] == SB[i]) {
                dp[k][i] = dp[k-1][i-1] + 1;
            } else {
                dp[k][i] = dp[k][i-1];
                if (dp[k][i-1] < dp[k-1][i])
                    dp[k][i] = dp[k-1][i];
            }
        }
    }

    printf("%d\n", dp[la][lb]);

    return 0;
}
