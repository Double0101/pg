#include <cstdio>
#include <cmath>
int ans[101];
int lie[101];
int wolf[101];
int count = 0, N;
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", ans+i);
        wolf[i] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            wolf[i] = wolf[j] = -1;
            count = 0;
            for (int k = 1; k <= N; ++k) {
                if (wolf[abs(ans[k])]*ans[k] < 0)
                    lie[count++] = k;
            }
            if (count == 2 && wolf[lie[0]]*wolf[lie[1]] == -1) {
                printf("%d %d\n", i, j);
                return 0;
            }
            wolf[i] = wolf[j] = 1;
        }
    }
    printf("No Solution\n");
    return 0;
}
