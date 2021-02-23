#include <cstdio>
#include <vector>

using namespace std;

int N, unique = 1;
vector<int> preorder;
vector<int> postorder;
vector<int> inorder;
int num = 0;

void build(int pres, int pree, int poss, int pose)
{
    int ps = poss;
    if (pres != pree) {
        while (postorder[ps] != preorder[pres+1]) ++ps;
        build(pres+1, pres+ps-poss+1, poss, ps);
        if (ps == pose-1) unique = 0;
    }
    inorder[num++] = preorder[pres];
    if (pres != pree && ps != pose-1) {
        build(pres+ps-poss+2, pree, ps+1, pose-1);
    }
}

int main()
{
    scanf("%d", &N);
    preorder.resize(N);
    postorder.resize(N);
    inorder.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(preorder[i]));
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(postorder[i]));
    }
    build(0, N-1, 0, N-1);
    if (unique == 1) printf("Yes\n");
    else printf("No\n");
    for (int i = 0; i < N - 1; ++i) {
        printf("%d ", inorder[i]);
    }
    printf("%d\n", inorder[N-1]);
    return 0;
}
