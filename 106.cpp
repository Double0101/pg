#include <cstdio>
#include <vector>

using namespace std;

int N, lc = 0;
double price, r, low = 10000000000;
vector<vector<int>> children;

void dfs(int index, double p)
{
    double np = p*r;
    for (int i : children[index]) {
        dfs(i, np);
    }
    if (children[index].empty()) {
        if (p < low) {
            low = p;
            lc = 0;
        }
        if (p == low) ++lc;
    }
}

int main()
{
    scanf("%d %lf %lf", &N, &price, &r);
    children.resize(N);
    int cn, c;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &cn);
        for (int j = 0; j < cn; ++j) {
            scanf("%d", &c);
            children[i].push_back(c);
        }
    }
    r = 1+r/100;
    dfs(0, price);
    printf("%.4lf %d\n", low, lc);
    return 0;
}
