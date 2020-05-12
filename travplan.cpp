#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int citynum, hwnum, scity, dcity;
int **hwnet;
int **costnet;

bool *visited;
int *dis;
int *cost;

vector<int> **paths;

inline
void changeway(int k, int cno) {
    vector<int> *p = paths[k];
    p->clear();
    for (int j = 0; j < paths[cno]->size(); ++j) {
        p->push_back((*paths[cno])[j]);
    }
    p->push_back(k);
}

void trace()
{
    dis[scity] = 0;
    cost[scity] = 0;
    paths[scity]->push_back(scity);
    for (int i = 0; i < citynum; ++i) {
        int min = INT_MAX, cno = -1;
        for (int j = 0; j < citynum; ++j) {
            if (!visited[j] && dis[j] < min) {
                min = dis[j];
                cno = j;
            }
        }

        if (cno == -1) return;
        visited[cno] = true;
        if (cno == dcity) return;
        int *cityway = hwnet[cno];
        for (int k = 0; k < citynum; ++k) {
            if (!visited[k] && cityway[k] < INT_MAX) {
                if (dis[k] == dis[cno] + cityway[k]) {
                    if (cost[k] > cost[cno] + costnet[cno][k]) {
                        cost[k] = cost[cno] + costnet[cno][k];
                        changeway(k, cno);
                    }
                } else if (dis[k] > dis[cno] + cityway[k]) {
                    dis[k] = dis[cno] + cityway[k];
                    cost[k] = cost[cno] + costnet[cno][k];
                    changeway(k, cno);
                }
            }
        }
    }
}

int main()
{
    cin >> citynum >> hwnum >> scity >> dcity;
    hwnet = (int**) malloc(sizeof(int*) * citynum);
    costnet = (int**) malloc(sizeof(int*) * citynum);
    dis = (int*) malloc(sizeof(int) * citynum);
    fill(dis, dis + citynum, INT_MAX);
    cost = (int*) malloc(sizeof(int) * citynum);
    fill(cost, cost + citynum, INT_MAX);
    visited = (bool*) malloc(sizeof(bool) * citynum);
    fill(visited, visited + citynum, false);
    paths = (vector<int>**) malloc(sizeof(vector<int>*) * citynum);
    for (int i = 0; i < citynum; ++i) {
        hwnet[i] = (int*) malloc(sizeof(int) * citynum);
        costnet[i] = (int*) malloc(sizeof(int) * citynum);
        int *w = hwnet[i];
        fill(w, w + citynum, INT_MAX);
        int *c = costnet[i];
        fill(c, c + citynum, 0);
        w[i] = 0;
        paths[i] = new vector<int>();
    }

    for (int j = 0; j < hwnum; ++j) {
        int c1, c2, d, co;
        cin >> c1 >> c2 >> d >> co;
        hwnet[c1][c2] = d;
        hwnet[c2][c1] = d;
        costnet[c1][c2] = co;
        costnet[c2][c1] = co;
    }
    trace();
    for (int k = 0; k < paths[dcity]->size(); ++k) {
        cout << (*paths[dcity])[k] << " ";
    }
    cout << dis[dcity] << " " << cost[dcity];
    return 0;
}