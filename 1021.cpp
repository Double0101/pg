#include <cstdio>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> connect;
vector<bool> visit;
int N;
int deep = -1;
set<int> node, tmpnode;
void dfs(int r, int d) {
    if (visit[r] == true) return;
    visit[r] = true;
    for (int i : connect[r]) {
        dfs(i, d+1);
    }
    if (d > deep) {
        deep = d;
        tmpnode.clear();
    }
    if (d == deep) {
        tmpnode.insert(r);
    }
}
int main()
{
    scanf("%d", &N);
    int a, b;
    connect.resize(N+1);
    for (int i = 1; i < N; ++i) {
        scanf("%d%d", &a, &b);
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    visit.resize(N+1,false);
    int com = 0;
    for (int i = 1; i <= N; ++i) {
        if (visit[i] == false) {
            dfs(i, 0);
            ++com;
        }
    }
    if (com > 1) {
        printf("Error: %d components\n", com);
        return 0;
    } else {
        fill(visit.begin(), visit.end(), false);
        node.insert(tmpnode.begin(), tmpnode.end());
        tmpnode.clear();
        deep = -1;
        dfs(*node.begin(), 0);
        node.insert(tmpnode.begin(), tmpnode.end());
        for (int i : node) {
            printf("%d\n", i);
        }
    }
    return 0;
}
