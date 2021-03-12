#include <cstdio>
#include <algorithm>
using namespace std;
int N, num = 0;
int inorder[20], preorder[20];
bool level[20];

void dfs(int is, int ie, int ps, int pe, int l)
{
    if (is > ie) return;
    if (level[l] == false) {
        if (num++ != 0) printf(" ");
        level[l] = true;
        printf("%d", preorder[ps]);
    }
    int prn = preorder[ps], irn = is;
    while (inorder[irn] != prn) ++irn;
    dfs(is, irn-1, ps+1, irn-is+ps, l+1);
    dfs(irn+1, ie, irn+1-ie+pe, pe, l+1);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", inorder+i);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", preorder+i);
    }
    fill(level, level+20, false);
    dfs(0, N-1, 0, N-1, 0);
    return 0;
}
