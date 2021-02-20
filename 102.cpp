#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct node {
    int lc, rc;
} node;
node ns[10];
int father[10];
int N, num = 0;
char str[5];

void inorder(int r)
{
    if (ns[r].lc != -1) inorder(ns[r].lc);
    if (num++ != 0) printf(" ");
    printf("%d", r);
    if (ns[r].rc != -1) inorder(ns[r].rc);
}
int main()
{
    fill(father, father+10, -1);
    scanf("%d\n", &N);
    int r, l, nil = '-'-'0';
    for (int i = 0; i < N; ++i) {
        cin.getline(str, 5);
        r = str[0]-'0';
        l = str[2]-'0';
        if (r == nil) r = -1;
        if (l == nil) l = -1;
        ns[i].rc = r;
        ns[i].lc = l;
        if (r != -1)
            father[r] = i;
        if (l != -1)
            father[l] = i;
    }
    int root;
    for (int i = 0; i < N; ++i) {
        if (father[i] == -1) root = i;
    }
    queue<int> q;
    printf("%d", root);
    if (ns[root].lc != -1) q.push(ns[root].lc);
    if (ns[root].rc != -1) q.push(ns[root].rc);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        printf(" %d", t);
        if (ns[t].lc != -1) q.push(ns[t].lc);
        if (ns[t].rc != -1) q.push(ns[t].rc);
    }
    printf("\n");
    inorder(root);
    printf("\n");
    return 0;
}
