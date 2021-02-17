#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> inorder;
vector<int> preorder;
vector<int> stack;
vector<int> inpos, prepos;
bool p = false;
void buildlevel(int istart, int iend, int pstart, int pend)
{
    if (istart > iend) return;
    int mid = preorder[pstart];
    int pi = inpos[mid];
    if (istart != iend) {
        buildlevel(istart, pi-1, pstart+1, pstart+pi-istart);
        buildlevel(pi+1, iend, pstart+pi-istart+1, pend);
    }
    if (p) printf(" ");
    else p = true;
    printf("%d", mid);
}

int main()
{
    char opt[5];
    int inn;
    scanf("%d", &N);
    inpos.resize(N+1);
    prepos.resize(N+1);
    for (int i = 0; i < N*2; ++i) {
        scanf("%s", opt);
        if (strcmp(opt, "Push") == 0) {
            scanf("%d", &inn);
            preorder.push_back(inn);
            prepos[inn] = preorder.size()-1;
            stack.push_back(inn);
        } else {
            inorder.push_back(stack[stack.size()-1]);
            inpos[stack[stack.size()-1]] = inorder.size()-1;
            stack.pop_back();
        }
    }
    buildlevel(0, N-1, 0, N-1);

    return 0;
}