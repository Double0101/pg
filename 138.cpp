#include <cstdio>

int N;
int preorder[50000];
int inorder[50000];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", preorder+i);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", inorder+i);
    }
    int ps = 0, pe = N-1, is = 0, ie = N-1, r;
    while (ps <= pe) {
        r = preorder[ps];
        int irpos = is;
        while (irpos <= ie && inorder[irpos] != r) ++irpos;
        if (irpos > is) {
            ie = irpos-1;
            ps = ps+1;
            pe = ps+ie-is;
        } else {
            ps += 1;
            is += 1;
        }
    }
    printf("%d\n", r);
    return 0;
}
