#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map<int, int> pos;
int preorder[10001];
int inorder[10001];
int M, N;

void lca(int inl, int inr, int preRoot, int a, int b)
{
    if (inl > inr) return;
    int inRoot = pos[preorder[preRoot]], ina = pos[a], inb = pos[b];
    if (inRoot > ina && inRoot > inb)
        lca(inl, inRoot-1, preRoot+1, a, b);
    else if ((ina < inRoot && inb > inRoot) || (ina > inRoot && inb < inRoot))
        printf("LCA of %d and %d is %d.\n", a, b, inorder[inRoot]);
    else if (inRoot < ina && inRoot < inb)
        lca(inRoot+1, inr, preRoot+inRoot-inl+1, a, b);
    else if (ina == inRoot)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (inb == inRoot)
        printf("%d is an ancestor of %d.\n", b, a);
}
int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", inorder+i);
        pos[inorder[i]] = i;
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", preorder+i);
    }
    int a, b, ap, bp;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        if (pos[a] == 0 && pos[b] == 0) printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0) printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else {
            lca(1, N, 1, a, b);
        }
    }
    return 0;
}
