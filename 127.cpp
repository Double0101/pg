#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node {
    int data, lc, rc, level;
} node;

int N;
int inorder[30];
int postorder[30];
node ns[30];

int build(int is, int ie, int ps, int pe, int level)
{
    if (ie < is) return -1;
    int root = postorder[pe];
    int ir = is;
    while (inorder[ir] != root) ++ir;
    int lr = build(is, ir-1, ps, ps+ir-1-is, level+1);
    int rr = build(ir+1, ie, ps+ir-is, pe-1, level+1);
    ns[ir].lc = lr;
    ns[ir].rc = rr;
    ns[ir].level = level;
    return ir;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", inorder+i);
        ns[i].data = inorder[i];
        ns[i].lc = ns[i].rc = -1;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", postorder+i);
    }
    int root = build(0, N-1, 0, N-1, 0);
    int direct = 0, level = 0;
    vector<int> ln;
    queue<int> q;
    if (ns[root].lc != -1) q.push(ns[root].lc);
    if (ns[root].rc != -1) q.push(ns[root].rc);
    ln.push_back(root);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        if (ns[t].level != level) {
            if (level%2 == 0) {
                for (int i = ln.size()-1; i >= 0; --i) {
                    if (level != 0) printf(" ");
                    printf("%d", ns[ln[i]].data);
                }
            } else {
                for (int i = 0; i < ln.size(); ++i) {
                    printf(" %d", ns[ln[i]].data);
                }
            }
            ln.clear();
            level = ns[t].level;
        }
        ln.push_back(t);
        if (ns[t].lc != -1) q.push(ns[t].lc);
        if (ns[t].rc != -1) q.push(ns[t].rc);
    }
    if (level%2 == 0) {
        for (int i = ln.size()-1; i >= 0; --i) {
            if (level != 0) printf(" ");
            printf("%d", ns[ln[i]].data);
        }
    } else {
        for (int i = 0; i < ln.size(); ++i) {
            printf(" %d", ns[ln[i]].data);
        }
    }
    printf("\n");
    return 0;
}
