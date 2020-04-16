#include <cstdio>
#include <cstdlib>
#include <queue>


typedef struct bnode {
    char data;
    bnode *rnode, *lnode;
} bnode;

inline
bnode* newNode(char a)
{
    bnode *n = (bnode*) malloc(sizeof(bnode));
    n->data = a;
    n->lnode = n->rnode = NULL;
    return n;
}

bnode* build(char* post, char* in, int l)
{
    if (l == 0)
        return NULL;
    char* c;
    char rc = post[l - 1];
    bnode *r = newNode(rc);
    c = in;
    while(*c != rc) ++c;
    int cc = c - in;
    r->lnode = build(post, in, cc);
    r->rnode = build(post + cc, in + cc + 1, l - cc - 1);
    return r;
}

void leveltra(bnode* root)
{
    std::queue<bnode*> q;
    q.push(root);
    while (!q.empty())
    {
        bnode* n = q.front();
        printf("%c", n->data);
        if (n->lnode != NULL) q.push(n->lnode);
        if (n->rnode != NULL) q.push(n->rnode);
        q.pop();
    }
}

int main()
{
    int count;
    scanf("%d", &count);
    char *post = (char*) malloc(sizeof(char) * count + 1);
    char *in = (char*) malloc(sizeof(char) * count + 1);
    fflush(stdin);
    gets(post);
    gets(in);
    bnode* root = build(post, in, count);

    leveltra(root);
    return 0;
}
