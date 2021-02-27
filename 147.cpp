#include <cstdio>

int N, M, num;
int heap[1001];

void dfs(int r, int max)
{
    if (r > max) return;
    dfs(2*r, max);
    dfs(2*r+1, max);
    if (num++ != 0) printf(" ");
    printf("%d", heap[r]);
}

int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", heap+j);
        }
        int minn = 1, maxn = 1;
        for (int j = 2; j <= N; ++j) {
            if (heap[j] > heap[j/2]) maxn = 0;
            if (heap[j] < heap[j/2]) minn = 0;
        }
        if (minn == 1) printf("Min Heap\n");
        else if (maxn == 1) printf("Max Heap\n");
        else printf("Not Heap\n");
        num = 0;
        dfs(1, N);
        printf("\n");
    }
    return 0;
}