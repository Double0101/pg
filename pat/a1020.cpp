#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct node {
    int data;
    struct node *lc, *rc;
} Node;

Node* newNode(int d)
{
    Node *nn = (Node*) malloc(sizeof(Node));
    nn->data = d;
    nn->lc = nn->rc = NULL;
    return nn;
}

int num;
int postorder[50];
int inorder[50];

void build(int ins, int ine, int pos, int poe, Node* root, int lor)
{
    if (ine < ins) return;
    int nd = postorder[poe];
    Node * n = newNode(nd);
    if (lor == 0) {
        root->lc = n;
    } else {
        root->rc = n;
    }
    if (poe == pos) return;
    int inp = ins;
    while (inorder[inp] != nd && inp <= ine) ++inp;
    int pl = inp - ins;
    build(ins, inp-1, pos, pos+pl-1, n, 0);
    build(inp+1, ine, pos+pl, poe-1, n, 1);
}

int main()
{
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        scanf("%d", postorder+i);
    }
    for (int j = 0; j < num; ++j) {
        scanf("%d", inorder+j);
    }
    Node *rot = newNode(-1);
    build(0, num-1, 0, num-1, rot, 0);
    Node *r = rot->lc;
    free(rot);

    queue<Node*> nq;
    printf("%d", r->data);
    if (r->lc != NULL) nq.push(r->lc);
    if (r->rc != NULL) nq.push(r->rc);
    free(r);
    while (!nq.empty()) {
        Node *n = nq.front();
        nq.pop();
        printf(" %d", n->data);
        if (n->lc != NULL) nq.push(n->lc);
        if (n->rc != NULL) nq.push(n->rc);
        free(n);
    }

    return 0;
}
