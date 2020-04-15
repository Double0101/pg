#include <cstdio>
#include <cstdlib>
#include <queue>

typedef struct bnode {
    int data;
    bnode *rnode, *lnode;
} bnode;

inline
bnode* newNode(int a)
{
    bnode *n = (bnode*) malloc(sizeof(bnode));
    n->data = a;
    n->lnode = n->rnode = NULL;
    return n;
}

bnode* institute()
{
    bnode* n1 = newNode(1);
    bnode* n2 = newNode(2);
    bnode* n3 = newNode(3);
    bnode* n4 = newNode(4);
    bnode* n5 = newNode(5);
    bnode* n6 = newNode(6);
    n1->lnode = n2;
    n1->rnode = n3;
    n2->lnode = n4;
    n2->rnode = n5;
    n3->rnode = n6;

    return n1;
}

void preorder(bnode *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->lnode);
    preorder(root->rnode);
}

void inorder(bnode *root)
{
    if (root == NULL) return;
    inorder(root->lnode);
    printf("%d ", root->data);
    inorder(root->rnode);
}

void postorder(bnode *root)
{
    if (root == NULL) return;
    postorder(root->lnode);
    postorder(root->rnode);
    printf("%d ", root->data);
}

void layerorder(bnode *root)
{
    std::queue<bnode*> nq;
    nq.push(root);
    while(!nq.empty())
    {
        bnode *n = nq.front();
        if (n->lnode != NULL)
            nq.push(n->lnode);
        if (n->rnode != NULL)
            nq.push(n->rnode);
        nq.pop();
        printf("%d ", n->data);
    }
}

int main()
{
    bnode *root = institute();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    layerorder(root);
    printf("\n");
    return 0;
}