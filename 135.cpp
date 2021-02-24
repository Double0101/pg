#include <cstdio>
#include <cmath>
using namespace std;

int K, N, flag;
int ns[50];
int bn;

int dfs(int start, int end, int black)
{
    if (start > end) {
        if (bn == -1) {
            bn = black;
        }
        if (black != bn) flag = 0;
        return 1;
    }
    int abr = abs(ns[start]);
    int s = start;
    while (s <= end && abs(ns[s]) <= abr) ++s;
    if (ns[start] >= 0) black+=1;
    int lr = dfs(start+1, s-1, black);
    int rr = dfs(s, end, black);
    if (ns[start] < 0 && (lr < 0 || rr < 0)) flag = 0;
    return ns[start];
}

int main()
{
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &N);
        flag = 1;
        for (int j = 0; j < N; ++j) {
            scanf("%d", ns+j);
        }
        bn = -1;
        int r = dfs(0, N-1, 0);
        if (r < 0) flag = 0;
        if (flag == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
