#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> children;
vector<int> lmem;

void dfs(int root, int level)
{
    ++lmem[level];
    for (int c : children[root]) {
        dfs(c, level+1);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    children.resize(N+1);
    lmem.resize(N+1, 0);
    int r, k, m;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &r, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &m);
            children[r].push_back(m);
        }
    }
    dfs(1, 1);
    int max = -1, ml = -1;
    for (int i = 1; i <= N; ++i) {
        if (lmem[i] > max) {
            max = lmem[i];
            ml = i;
        }
    }
    printf("%d %d\n", max, ml);
    return 0;
}
