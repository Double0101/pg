#include <cstdio>
#include <algorithm>
using namespace std;

int N, num[1000], nnn = 0;
int tree[1001];
void dfs(int r) {
    if (r > N) return;
    dfs(r*2);
    tree[r] = num[nnn++];
    dfs(r*2+1);
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", num+i);
    }
    sort(num, num+N);
    dfs(1);
    for (int i = 1; i < N; ++i) {
        printf("%d ", tree[i]);
    }
    printf("%d\n", tree[N]);
    return 0;
}
