#include <iostream>
#include <queue>

using namespace std;

bool **G;

int cnum, rnum;
int *indegree;

int* topsort()
{
    int o = 0;
    queue<int> cq;
    for (int i = 0; i < cnum; ++i) {
        if (indegree[i] == 0) {
            cq.push(i);
        }
    }
    int *ans = (int*) malloc(sizeof(int) * cnum);
    while (!cq.empty()) {
        int a = cq.front();
        ans[o] = a;
        ++o;
        cq.pop();
        bool *g = G[a];
        for (int i = 0; i < cnum; ++i) {
            if (g[i]) {
                --indegree[i];
                if (indegree[i] == 0) {
                    cq.push(i);
                }
            }
        }
    }

    if (o == cnum)
        return ans;
    return NULL;
}

int main()
{
    cin >> cnum >> rnum;
    G = (bool**) malloc(sizeof(bool*) * cnum);
    for (int i = 0; i < cnum; ++i) {
        G[i] = (bool*) malloc(sizeof(bool) * cnum);
        bool *g = G[i];
        fill(g, g+cnum, false);
    }

    indegree = (int*) malloc(sizeof(int) * cnum);

    for (int j = 0; j < rnum; ++j) {
        int c1, c2;
        cin >> c1 >> c2;
        G[c1][c2] = true;
        indegree[c2] += 1;
    }

    int *a = topsort();
    if (a == NULL) return 0;
    for (int k = 0; k < cnum; ++k) {
        cout << a[k] << " ";
    }
    cout << endl;
    return 0;
}