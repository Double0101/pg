#include <cstdio>
#include <cstring>

int power[21], N, K, P, end = 0, flag = 0, ss = 0;
int tmplist[400], list[400];
void dfs(int r, int index, int sum, int psum)
{
    if (psum > N) return;
    if (index == K) {
        if (psum == N) {
            if (sum > ss) {
                flag = 1;
                ss = sum;
                memcpy(list, tmplist, sizeof(int)*K);
            }
        }
        return;
    }
    while (r > 0) {
        if (power[r] <= N-psum) {
            tmplist[index] = r;
            dfs(r, index+1, sum+r, psum+power[r]);
        }
        --r;
    }
}

int main()
{
    scanf("%d%d%d", &N, &K, &P);
    power[0] = 0;
    for (int i = 1; i <= 20; ++i) {
        int pp = 1;
        for (int j = 0; j < P; ++j)
            pp*=i;
        if (pp <= N) {
            power[i] = pp;
            end = i;
        } else break;
    }
    dfs(end, 0, 0, 0);
    if (flag == 1) {
        printf("%d = ", N);
        for (int i = 0; i < K-1; ++i) {
            printf("%d^%d + ", list[i], P);
        }
        printf("%d^%d\n", list[K-1], P);
    } else printf("Impossible\n");
    return 0;
}
