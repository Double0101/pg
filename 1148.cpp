#include <cstdio>
#include <algorithm>

using namespace std;

int ans[101];
int liar[101];
int wolf[101];
int main()
{
    int N;
    scanf("%d", &N);
    fill(wolf, wolf + N + 1, 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", ans+i);
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            wolf[i] = wolf[j] = -1;
            int count = 0;
            for (int k = 1; k <= N; ++k) {
                if (wolf[abs(ans[k])]*ans[k] < 0) {
                    liar[count++] = k;
                }
            }
            if (count == 2 && wolf[liar[0]]+wolf[liar[1]] == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
            wolf[i] = wolf[j] = 1;
        }
    }
    printf("No Solution\n");
    return 0;
}
