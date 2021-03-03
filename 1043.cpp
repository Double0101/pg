#include <cstdio>
#include <vector>
using namespace std;
int preorder[1000];
vector<int> postorder;
int N, mirror = 0;

void dfs(int start, int end) {
    if (start > end) return;
    int i = start+1, j = end;
    if (mirror == 0) {
        while (i <= end && preorder[i] < preorder[start]) ++i;
        while (j > start && preorder[j] >= preorder[start]) --j;
    } else {
        while (i <= end && preorder[i] >= preorder[start]) ++i;
        while (j > start && preorder[j] < preorder[start]) --j;
    }
    if (i-j != 1) return;
    dfs(start+1, j);
    dfs(i, end);
    postorder.push_back(preorder[start]);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", preorder+i);
    }
    dfs(0, N-1);
    if (postorder.size() != N) {
        mirror = 1;
        postorder.clear();
        dfs(0, N-1);
    }
    if (postorder.size() != N) {
        printf("NO\n");
    } else {
        printf("YES\n%d", postorder[0]);
        for (int i = 1; i < N; ++i) {
            printf(" %d", postorder[i]);
        }
        printf("\n");
    }
    return 0;
}
