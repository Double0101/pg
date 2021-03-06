#include <cstdio>
#include <unordered_map>
using namespace std;

int inorder[10000];
int preorder[10000];
int M, N;
unordered_map<int, int> ss;
void LCA(int is, int ie, int ps, int pe, int a, int b)
{
    if (is > ie) return;
    int ai = ss[a], bi = ss[b], inRoot = ss[preorder[ps]];
    if (ai > inRoot && bi > inRoot) LCA(inRoot + 1, ie, inRoot + 1 - ie + pe, pe, a, b);
    else if (inRoot == ai || inRoot == bi)
        printf("%d is an ancestor of %d.\n", inRoot == ai ? a : b, inRoot == ai ? b : a);
    else if (ai < inRoot && bi < inRoot) LCA(is, inRoot - 1, ps + 1, inRoot - is + ps, a, b);
    else printf("LCA of %d and %d is %d.\n", a, b, preorder[ps]);
}
int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", inorder+i);
        ss[inorder[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", preorder+i);
    }
    int a, b;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        bool ba = ss.find(a) == ss.end(), bb = ss.find(b) == ss.end();
        if (ba && bb) printf("ERROR: %d and %d are not found.\n", a, b);
        else if ((!ba) && (!bb))
            LCA(0, N - 1, 0, N - 1, a, b);
        else printf("ERROR: %d is not found.\n", ba ? a : b);
    }
    return 0;
}
