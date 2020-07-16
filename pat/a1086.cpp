#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

char str[20];
char *push = "Push";

typedef struct node {
    int data;
    struct node *lc, *rc;
    int lv, rv;
} Node;

Node* newNode(int d)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->data = d;
    n->lc = NULL;
    n->rc = NULL;
    n->lv = n->rv = 0;
    return n;
}

int num;
int ddd;

stack<Node*> nstack;

int visit(Node *no)
{
    if (no->lv == 0) {
        no->lv = 1;
        return 0;
    }
    if (no->rv == 0) {
        no->rv = 1;
        return 1;
    }
    return 2;
}

void postTra(Node* nod, Node *r)
{
    if (nod->lc != NULL) {
        postTra(nod->lc, r);
    }
    if (nod->rc != NULL) {
        postTra(nod->rc, r);
    }
    printf("%d", nod->data);
    if (nod != r) printf(" ");
    else printf("\n");
    free(nod);
}

int main()
{
    scanf("%d", &num);
    int f = 2*num;
    Node* root = newNode(-1);
    nstack.push(root);
    for (int i = 0; i < f; ++i) {
        scanf("%s", str);
        Node *top = nstack.top();
        int lr = visit(top);
        if (strcmp(str, push) == 0) {
            scanf("%d", &ddd);
            Node *nwn = newNode(ddd);
            if (lr == 0) {
                top->lc = nwn;
            } else {
                top->rc = nwn;
                nstack.pop();
            }
            nstack.push(nwn);
        } else {
            if (lr == 1) {
                nstack.pop();
            }
        }
    }
    postTra(root->lc, root->lc);

    return 0;
}