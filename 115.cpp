#include <cstdio>
#include <vector>

using namespace std;

typedef struct Node {
    int data, lc, rc;
} node;
int N;
vector<node> BST;
int lnum[1000] = {0};
int maxLevel = 0;

void dfs(int index, int level)
{
    ++lnum[level];
    if (level > maxLevel) maxLevel = level;
    if (BST[index].lc != -1) dfs(BST[index].lc, level+1);
    if (BST[index].rc != -1) dfs(BST[index].rc, level+1);
}

int findPos(int index, int num)
{
    if (num <= BST[index].data && BST[index].lc != -1) {
        return findPos(BST[index].lc, num);
    }
    else if (num > BST[index].data && BST[index].rc != -1) {
        return findPos(BST[index].rc, num);
    }
    return index;
}

int main()
{
    scanf("%d", &N);
    BST.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(BST[i].data));
        BST[i].lc = BST[i].rc = -1;
    }
    int f;
    for (int i = 1; i < N; ++i) {
        f = findPos(0, BST[i].data);
        if (BST[i].data <= BST[f].data) BST[f].lc = i;
        else BST[f].rc = i;
    }
    dfs(0, 0);
    printf("%d + %d = %d\n", lnum[maxLevel], lnum[maxLevel-1], lnum[maxLevel]+lnum[maxLevel-1]);
    return 0;
}