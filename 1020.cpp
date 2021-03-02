#include <cstdio>
#include <queue>
using namespace std;
int postorder[30];
int inorder[30];
int lc[30];
int rc[30];
int N;

int dfs(int ps, int pe, int is, int ie) {
    if (ps > pe) return -1;
    int ir = postorder[pe], irn = is;
    while (inorder[irn] != ir) ++irn;
    lc[pe] = dfs(ps, ps+irn-is-1, is, irn-1);
    rc[pe] = dfs(pe-ie+irn, pe-1, irn+1, ie);
    return pe;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", postorder+i);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", inorder+i);
    }
    int root = dfs(0, N-1, 0, N-1);
    queue<int> q;
    int num = 0;
    q.push(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (num++ != 0) printf(" ");
        printf("%d", postorder[t]);
        if (lc[t] != -1) q.push(lc[t]);
        if (rc[t] != -1) q.push(rc[t]);
    }
    printf("\n");
    return 0;
}
