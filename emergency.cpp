#include <iostream>
#include <climits>

using namespace std;

int citynum, roadnum, ca, cb;
int *ambs;
int **roads;
int *roadc;

int *dis;
bool *visited;
int *ambc;

void rescue()
{
    dis[ca] = 0;
    roadc[ca] = 1;
    for (int i = 0; i < citynum; ++i) {
        int min = INT_MAX, curcity = -1;
        for (int j = 0; j < citynum; ++j) {
            if (!visited[j] && dis[j] < min) {
                curcity = j;
                min = dis[j];
            }
        }
        if (curcity == -1) return;
        if (curcity == cb)
            return;
        visited[curcity] = true;
        for (int k = 0; k < citynum; ++k) {
            if (!visited[k] && roads[curcity][k] != INT_MAX) {
                if (dis[k] == dis[curcity] + roads[curcity][k]) {
                    roadc[k] += roadc[curcity];
                    if (ambc[k] < ambc[curcity] + ambs[k]) {
                        ambc[k] = ambc[curcity] + ambs[k];
                    }
                }
                if (dis[k] > dis[curcity] + roads[curcity][k]) {
                    dis[k] = dis[curcity] + roads[curcity][k];
                    ambc[k] = ambc[curcity] + ambs[k];
                    roadc[k] = roadc[curcity];
                }
            }
        }
    }
}

int main()
{
    cin >> citynum >> roadnum >> ca >> cb;
    ambs = (int*) malloc(sizeof(int) * citynum);
    roads = (int**) malloc(sizeof(int*) * citynum);
    roadc = (int*) malloc(sizeof(int) * citynum);
    visited = (bool*) malloc(sizeof(bool) * citynum);
    dis = (int*) malloc(sizeof(int) * citynum);
    ambc = (int*) malloc(sizeof(int) * citynum);
    for (int j = 0; j < citynum; ++j) {
        visited[j] = false;
        dis[j] = INT_MAX;
        roadc[j] = 0;
        roads[j] = (int*) malloc(sizeof(int) * citynum);
        int *r = roads[j];
        fill(r, r+citynum, INT_MAX);
        r[j] = 0;
    }
    for (int i = 0; i < citynum; ++i) {
        cin >> ambs[i];
    }
    memcpy(ambc, ambs, sizeof(int) * citynum);
    for (int k = 0; k < roadnum; ++k) {
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        roads[c1][c2] = len;
        roads[c2][c1] = len;
    }
    rescue();
    cout << roadc[cb] << " " << ambc[cb] << endl;

    return 0;
}