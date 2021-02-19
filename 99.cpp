#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct node {
    int data, lc, rc;
} node;
int N, n = 0;
vector<node> ns;
vector<int> datas;

void inorder(int root)
{
    if (root == -1) return;
    inorder(ns[root].lc);
    ns[root].data = datas[n++];
    inorder(ns[root].rc);
}

int main()
{
    scanf("%d", &N);
    ns.resize(N), datas.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &(ns[i].lc), &(ns[i].rc));
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(datas[i]));
    }
    sort(datas.begin(), datas.end());
    inorder(0);
    queue<int> q;
    printf("%d", ns[0].data);
    if (ns[0].lc != -1) q.push(ns[0].lc);
    if (ns[0].rc != -1) q.push(ns[0].rc);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        printf(" %d", ns[t].data);
        if (ns[t].lc != -1) q.push(ns[t].lc);
        if (ns[t].rc != -1) q.push(ns[t].rc);
    }
    printf("\n");
    return 0;
}