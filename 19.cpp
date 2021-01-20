#include <cstdio>
#include <queue>

using namespace std;

typedef struct node {
    int data;
    struct node *lc, *rc;
} node;

int N;
int pos[30], in[30];
queue<node*> q;

node* buildlevel(int ps, int pe, int is, int ie)
{
    if (pe < ps || ie < is) return NULL;
    node *root = new node();
    root->data = pos[pe];
    int i;
    for (i = is; i <= ie; ++i) {
        if (in[i] == pos[pe]) break;
    }
    int pp = ps+i-is-1;
    root->lc = buildlevel(ps, pp, is, i-1);
    root->rc = buildlevel(pp+1, pe-1, i+1, ie);
    return root;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", pos+i);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", in+i);
    }
    node *n = buildlevel(0, N-1, 0, N-1);
    q.push(n);
    while (!q.empty()) {
        node *nn = q.front();
        q.pop();
        if (nn != n) printf(" ");
        printf("%d", nn->data);
        if (nn->lc) q.push(nn->lc);
        if (nn->rc) q.push(nn->rc);
        delete(nn);
    }
    return 0;
}