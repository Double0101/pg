#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, a, root, mc = 0, ml = 0;
double price, rate;
vector<vector<int>> supplier;

void dfs(int root, int level) {
    if (level > ml) {
        ml = level;
        mc = 0;
    }
    if (level == ml) ++mc;
    for (int n : supplier[root]) {
        dfs(n, level+1);
    }
}

int main()
{
    scanf("%d%lf%lf", &N, &price, &rate);
    supplier.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        if (a != -1)
            supplier[a].push_back(i);
        else root = i;
    }
    rate = 1+rate/100;
    dfs(root, 0);
    for (int i = 0; i < ml; ++i) {
        price *= rate;
    }
    printf("%.02lf %d\n", price, mc);
    return 0;
}
