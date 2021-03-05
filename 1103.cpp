#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int power[21];
int N, P, K, ansum = 0;
vector<int> ans, tmp;

void dfs(int index, int nc, int psum, int nsum)
{
    if (nc == K) {
        if (psum == N && nsum > ansum) {
            ans = tmp;
            ansum = nsum;
        }
        return;
    }
    while (index > 0) {
        if (power[index] <= N-psum) {
            tmp[nc] = index;
            dfs(index, nc+1, psum+power[index], nsum+index);
        }
        --index;
    }
}

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    int start = 1;
    for (int i = 0; i < 21; ++i) {
        power[i] = i;
        for (int j = 1; j < P; ++j) {
            power[i] *= i;
        }
        if (power[i] <= N) {
            start = i;
        } else break;
    }
    tmp.resize(K);
    dfs(start, 0, 0, 0);
    if (ans.size() == K) {
        printf("%d = %d^%d", N, ans[0], P);
        for (int i = 1; i < K; ++i) {
            printf(" + %d^%d", ans[i], P);
        }
        printf("\n");
    } else {
        printf("Impossible\n");
    }
    return 0;
}
