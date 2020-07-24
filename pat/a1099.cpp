#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct BSNode {
    int data;
    int order;
    struct BSNode *lc, *rc;
} BSNode;

BSNode ns[110];
int ds[110];

vector<int> post;

int num;

bool cmp(int a, int b)
{
    return b >= a;
}

void midT(BSNode* root, vector<int> &out) {
    if (root->lc != NULL) {
        midT(root->lc, out);
    }
    out.push_back(root->order);
    if (root->rc != NULL) {
        midT(root->rc, out);
    }
}

int main()
{
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        ns[i].order = i;
        if (a != -1) {
            ns[i].lc = &(ns[a]);
        } else {
            ns[i].lc = NULL;
        }
        if (b != -1) {
            ns[i].rc = &(ns[b]);
        } else {
            ns[i].rc = NULL;
        }
    }
    midT(&(ns[0]), post);

    for (int j = 0; j < num; ++j) {
        scanf("%d", ds+j);
    }
    sort(ds, ds+num, cmp);
    for (int k = 0; k < post.size(); ++k) {
        ns[post[k]].data = ds[k];
    }
    queue<BSNode*> q;
    printf("%d", ns[0].data);
    if (ns[0].lc != NULL) q.push(ns[0].lc);
    if (ns[0].rc != NULL) q.push(ns[0].rc);
    while (!q.empty()) {
        BSNode *n = q.front();
        q.pop();
        printf(" %d", n->data);
        if (n->lc != NULL) q.push(n->lc);
        if (n->rc != NULL) q.push(n->rc);
    }
    printf("\n");

    return 0;
}
