#include <cstdio>
#include <vector>

using namespace std;

typedef struct node {
    int data;
    vector<int> child;
};

vector<node> snet;
int N;
double price, profit;
double total = 0;

void dfs(int index, double p) {
    if (snet[index].child.size() == 0) {
        total += (snet[index].data*p);
        return;
    }
    for (int i : snet[index].child) {
        dfs(i, p*profit);
    }
}

int main()
{
    scanf("%d%lf%lf", &N, &price, &profit);
    snet.resize(N);
    int a, b;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &b);
            snet[i].child.push_back(b);
        }
        if (a == 0) {
            scanf("%d", &b);
            snet[i].data = b;
        }
    }
    profit = 1 + profit/100;
    dfs(0, price);
    printf("%.01lf\n", total);
    return 0;
}
