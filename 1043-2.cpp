#include <cstdio>
#include <vector>

using namespace std;

vector<int> preorder;
int N;
bool isMirror = false;
vector<int> postorder;
void dfs(int s, int e)
{
    if (s > e) return;
    int a, b;
    if (!isMirror) {
        for (a = s+1; a <= e && preorder[a] < preorder[s]; ++a);
        for (b = e; b > s && preorder[b] >= preorder[s]; --b);
    } else {
        for (a = s+1; a <= e && preorder[a] >= preorder[s]; ++a);
        for (b = e; b > s && preorder[b] < preorder[s]; --b);
    }
    if (a-b != 1) return;
    dfs(s+1, b);
    dfs(a, e);
    postorder.push_back(preorder[s]);
}
int main()
{
    scanf("%d", &N);
    preorder.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(preorder[i]));
    }
    dfs(0, N-1);
    if (postorder.size() != N) {
        isMirror = true;
        postorder.clear();
        dfs(0, N-1);
    }
    if (postorder.size() != N) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < N-1; ++i) {
            printf("%d ", postorder[i]);
        }
        printf("%d\n", postorder[N-1]);
    }
}
