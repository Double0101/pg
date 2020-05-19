#include <iostream>
#include <queue>

using namespace std;

int **W;
int *e;
int *indegree;
int cnum, rnum;

bool aoe()
{
    queue<int> cq;
    int a = 0;
    for (int i = 0; i < cnum; ++i) {
        if (indegree[i] == 0) {
            cq.push(i);
        }
    }

    while (!cq.empty()) {
        int t = cq.front();
        cq.pop();
        ++a;
        int *w = W[t];
        for (int i = 0; i < cnum; ++i) {
            if (w[i] != INT_MAX) {
                --indegree[i];
                if (e[i] < e[t] + w[i]) {
                    e[i] = e[t] + w[i];
                }
                if (indegree[i] == 0) {
                    cq.push(i);
                }
            }
        }
    }
    if (a == cnum) return true;
    return false;
}

int main()
{
    cin >> cnum >> rnum;
    W = (int**) malloc(sizeof(int*) * cnum);
    for (int i = 0; i < cnum; ++i) {
        W[i] = (int*) malloc(sizeof(int) * cnum);
        int* w = W[i];
        fill(w, w+cnum, INT_MAX);
    }
    e = (int*) malloc(sizeof(int) * cnum);
    fill(e, e+cnum, 0);
    indegree = (int*) malloc(sizeof(int) * cnum);
    fill(indegree, indegree+cnum, 0);

    for (int j = 0; j < rnum; ++j) {
        int c1, c2, cost;
        cin >> c1 >> c2 >> cost;
        W[c1][c2] = cost;
        ++indegree[c2];
    }
    if (aoe()) {
        cout << e[18] << endl;
    }
    return 0;
}