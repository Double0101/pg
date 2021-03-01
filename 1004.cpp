#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> children[100];
int N, M;
int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        for (int j = 0; j < b; ++j) {
            scanf("%d", &c);
            children[a].push_back(c);
        }
    }
    queue<int> q;
    int level = 0, cnum = 1;
    q.push(1);
    while (!q.empty()) {
        int num = 0, leaf = 0, node;
        for (int i = 0; i < cnum; ++i) {
            node = q.front();
            q.pop();
            if (children[node].empty()) ++leaf;
            for (int j : children[node]) {
                q.push(j);
                ++num;
            }
        }
        if (level++ != 0) printf(" ");
        printf("%d", leaf);
        cnum = num;
    }
    printf("\n");
    return 0;
}
