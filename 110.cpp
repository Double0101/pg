#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct node {
    int lc, rc;
}node;

int N;
vector<node> ns;
vector<int> father;
int isTree = 1;
int last, lpos = 0;
void dfs(int r, int pos) {
    if (pos >= N) {
        isTree = 0;
        return;
    }
    if (pos > lpos) {
        lpos = pos;
        last = r;
    }
    if (isTree == 1 && ns[r].lc != -1) dfs(ns[r].lc, pos*2+1);
    if (isTree == 1 && ns[r].rc != -1) dfs(ns[r].rc, pos*2+2);
}

int main()
{
    scanf("%d", &N);
    ns.resize(N);
    father.resize(N, -1);
    char s1[4], s2[4];
    for (int i = 0; i < N; ++i) {
        scanf("%s %s", s1, s2);
        int l, r;
        if (strcmp(s1, "-") == 0) l = -1;
        else {
            l = atoi(s1);
            father[l] = i;
        }
        if (strcmp(s2, "-") == 0) r = -1;
        else {
            r = atoi(s2);
            father[r] = i;
        }
        ns[i].lc = l, ns[i].rc = r;
    }
    int root;
    for (root = 0; root < N && father[root] != -1; ++root);
    dfs(root, 0);
    if (isTree == 1) printf("YES %d\n", last);
    else printf("NO %d\n", root);

    return 0;
}
