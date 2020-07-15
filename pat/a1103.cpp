#include <cstdio>
#include <vector>

using namespace std;

vector<int> table;

vector<int> ans, tmp;

int N, K, P, maxFac = -1;

int power(int x, int p)
{
    int an = 1;
    for (int i = 0; i < p; ++i) {
        an *= x;
    }
    return an;
}

void init()
{
    int i = 0, temp = 0;
    while (temp <= N) {
        table.push_back(temp);
        temp = power(++i, P);
    }
}

void DFS(int index, int nK, int sum, int facS)
{
    if (nK == K && sum == N) {
        if (facS > maxFac) {
            ans = tmp;
            maxFac = facS;
        }
    }
    if (sum > N || nK > K) return;
    if (index > 0) {
        tmp.push_back(index);
        DFS(index, nK+1, sum+table[index], facS+index);
        tmp.pop_back();
        DFS(index-1, nK, sum, facS);
    }
}

int main()
{
    scanf("%d %d %d", &N, &K, &P);
    init();
    DFS(table.size()-1, 0, 0, 0);
    if (maxFac == -1) {
        printf("Impossible\n");
    } else {
        printf("%d = %d^%d", N, ans[0], P);
        for (int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d", ans[i], P);
        }
    }

    return 0;
}