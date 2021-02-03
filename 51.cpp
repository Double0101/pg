#include <cstdio>
#include <vector>

using namespace std;

vector<int> stack;
int capacity;

void fff(int top, int cap, vector<int> &inorder) {
    int i = 1;
    stack.clear();
    for (int j = 0; j < inorder.size(); ++j) {
        while (i <= inorder[j] && stack.size() < cap) {
            stack.push_back(i++);
        }
        if (stack[stack.size()-1] != inorder[j]) {
            printf("NO\n");
            return;
        }
        stack.pop_back();
    }
    if (stack.size() == 0) printf("YES\n");
}

int main()
{
    int nnum, innum;
    scanf("%d %d %d", &capacity, &nnum, &innum);
    vector<int> in(nnum);
    for (int i = 0; i < innum; ++i) {
        for (int j = 0; j < nnum; ++j) {
            scanf("%d", &in[j]);
        }
        fff(nnum, capacity, in);
    }
    return 0;
}