#include <cstdio>
#include <vector>

using namespace std;

int N, K, P, sum = 0;
int power[401];
vector<int> tmpv, result;


void dfs(int n, int ts, int psum, int tmpsum)
{
    if (ts == K) {
        if (psum == N && tmpsum > sum) {
            result = tmpv;
            sum = tmpsum;
        }
        return;
    }
    while (n > 0) {
        if (psum+power[n] <= N) {
            tmpv[ts] = n;
            dfs(n, ts+1, psum+power[n], tmpsum+n);
        }
        --n;
    }
}

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    power[0] = 0;
    int n = 1;
    for (int i = 1; i <= N; ++i) {
        int p = 1;
        for (int j = 0; j < P; ++j) {
            p *= i;
        }
        if (p <= N) {
            power[i] = p;
            n = i;
        } else break;
    }
    tmpv.resize(K);
    dfs(n, 0, 0, 0);
    if (sum) {
        printf("%d = %d^%d", N, result[0], P);
        for (int i = 1; i < K; ++i) {
            printf(" + %d^%d", result[i], P);
        }
    } else {
        printf("Impossible\n");
    }
    return 0;
}
