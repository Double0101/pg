#include <cstdio>

int preorder[30];
int postorder[30];
int inorder[30];
int N, unique = 1, num = 0;

void dfs(int pres, int pree, int posts, int poste)
{
    if (pres > pree) return;
    int postlc = poste-1;
    while (postlc >= posts && postorder[postlc] != preorder[pres+1]) --postlc;
    if (postlc >= posts && postlc == poste-1) unique = 0;
    dfs(pres+1, postlc-posts+pres+1, posts, postlc);
    inorder[num++] = preorder[pres];
    dfs(postlc-poste+pree+2, pree, postlc+1, poste-1);
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
    if (unique == 0) printf("No\n");
    else printf("Yes\n");
    for (int i = 0; i < N-1; ++i) {
        printf("%d ", inorder[i]);
    }
    printf("%d\n", inorder[N-1]);
    return 0;
}
