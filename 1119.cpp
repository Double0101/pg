#include <cstdio>

int preorder[30], postorder[30], inorder[30];
int N, unique = 1, num = 0;

void dfs(int pres, int pree, int posts, int poste)
{
    if (pres > pree) return;
    int prelc = pres+1;
    int postlc = poste-1;
    while (postlc >= posts && postorder[postlc] != preorder[prelc]) --postlc;
    if (postlc >= posts && postlc == poste-1) unique = 0;
    dfs(prelc, postlc-posts+prelc, posts, postlc);
    inorder[num++] = preorder[pres];
    dfs(pree+postlc+2-poste, pree, postlc+1, poste-1);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", preorder+i);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", postorder+i);
    }
    dfs(0, N-1, 0, N-1);
    if (unique == 1) printf("Yes\n");
    else printf("No\n");
    for (int i = 0; i < N-1; ++i) {
        printf("%d ", inorder[i]);
    }
    printf("%d\n", inorder[N-1]);
    return 0;
}
