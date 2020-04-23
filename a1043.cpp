#include <cstdio>
#include <cstdlib>

typedef struct node {
    node *lc = NULL, *rc = NULL;
    int data;
} node;

node* newnode(int data)  {
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    return n;
}

bool isBST(int *arr, size_t count)
{
    if (count == 0)
        return true;
    int i = *arr;
    int *a = NULL;
    for (int j = 1; j < count; ++j) {
        if (arr[j] >= i) {
            a = arr + j;
            break;
        }
    }
    if (a == NULL) {
        return isBST(arr + 1, count - 1);
    }
    else {
        int c = a - arr - 1;
        for (int j = c + 1; j < count; ++j) {
            if (arr[j] < i) return false;
        }
        return isBST(arr + 1, c) && isBST(a, count - c - 1);
    }
}

node* BST(int *arr, int count)
{
    if (count == 0)
        return NULL;
    node* root = newnode(*arr);
    int i = 0;
    for (int j = 1; j < count; ++j) {
        if (arr[j] >= *arr) {
            i = j;
            break;
        }
    }
    if (i == 0) {
        root->lc = BST(arr + 1, count - 1);
    }
    else {
        root->lc = BST(arr + 1, i - 1);
        root->rc = BST(arr + i, count - i);
    }
    return root;
}

void postra(node* root)
{
    if (root == NULL) return;
    postra(root->lc);
    postra(root->rc);
    printf("%d ", root->data);
}

int main()
{
    int arr[] = {8, 10, 11, 8, 6, 7, 5};
    if (isBST(arr, 7)) {
        printf("true\n");
        postra(BST(arr, 7));
    }
    else
        printf("false\n");

    return 0;
}