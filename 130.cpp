#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Node {
    char data[15];
    int lc, rc;
} node;

int parent[21];
node ns[21];
int N, root = -1;

void inorder(int r)
{
    if (r != root && (ns[r].lc != -1 || ns[r].rc != -1))
        printf("(");
    if (ns[r].lc != -1) inorder(ns[r].lc);
    printf("%s", ns[r].data);
    if (ns[r].rc != -1) inorder(ns[r].rc);
    if (r != root && (ns[r].lc != -1 || ns[r].rc != -1))
        printf(")");
}

int main()
{
    scanf("%d", &N);
    fill(parent, parent+21, -1);
    for (int i = 1; i <= N; ++i) {
        scanf("%s %d %d", ns[i].data, &(ns[i].lc), &(ns[i].rc));
        if (ns[i].lc != -1) parent[ns[i].lc] = i;
        if (ns[i].rc != -1) parent[ns[i].rc] = i;
    }
    for (int i = 1; i <= N; ++i) {
        if (parent[i] == -1) root = i;
    }
    inorder(root);
    printf("\n");
    return 0;
}
