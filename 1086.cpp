#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector<int> preorder;
vector<int> inorder;
vector<int> stack;
int N, nn = 0;

void dfs(int ps, int pe, int is, int ie)
{
    if (ps > pe) return;
    int rpn = preorder[ps];
    int ir = is;
    while (inorder[ir] != rpn) ++ir;
    dfs(ps+1, ir-is+ps, is, ir-1);
    dfs(pe-ie+ir+1, pe, ir+1, ie);
    if (nn++ != 0) printf(" ");
    printf("%d", preorder[ps]);
}

int main()
{
    char opt[5];
    int num;
    scanf("%d", &N);
    for (int i = 0; i < 2 * N; ++i) {
        scanf("%s", opt);
        if (strcmp(opt, "Pop") == 0) {
            inorder.push_back(stack[stack.size()-1]);
            stack.pop_back();
        } else {
            scanf("%d", &num);
            stack.push_back(num);
            preorder.push_back(num);
        }
    }
    dfs(0, N-1, 0, N-1);
    printf("\n");
    return 0;
}
