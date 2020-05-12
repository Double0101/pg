#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef struct Road {
    int distance, destiny;
} Road;

vector<Road*> **roads;
int *dis;
int *inqnum;
bool *inq;

int citynum, roadnum, scity, ecity;

bool spfa(int s) {
    queue<int> cq;
    cq.push(s);
    inq[s] = true;
    dis[s] = 0;
    ++inqnum[s];
    while (!cq.empty()) {
        int nc = cq.front();
        cq.pop();
        inq[s] = false;
        int rsize = roads[s]-> size();
        for (int i = 0; i < rsize; ++i) {
            int v = (*roads[s])[i]->destiny;
            int ll = (*roads[s])[i]->distance;
            if (dis[v] > dis[s] + ll) {
                dis[v] = dis[s] + ll;
                if (!inq[v]) {
                    inq[v] = true;
                    ++inqnum[v];
                    cq.push(v);
                    if (inqnum[v] >= roadnum) return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    cin >> citynum >> roadnum >> scity >> ecity;
    dis = (int*) malloc(sizeof(int) * citynum);
    fill(dis, dis + citynum, INT_MAX);
    inq = (bool*) malloc(sizeof(bool) * citynum);
    fill(inq, inq + citynum, false);
    inqnum = (int*) malloc(sizeof(int) * citynum);
    memset(inqnum, 0, sizeof(int) * citynum);
    roads = (vector<Road*>**) malloc(sizeof(vector<Road*>*) * citynum);
    for (int i = 0; i < citynum; ++i) {
        roads[i] = new vector<Road*>();
    }
    for (int j = 0; j < roadnum; ++j) {
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        Road *r1, *r2;
        r1 = (Road*) malloc(sizeof(Road));
        r2 = (Road*) malloc(sizeof(Road));
        r1->destiny = c2;
        r1->distance = len;
        r2->destiny = c1;
        r2->distance = len;
        roads[c1]->push_back(r1);
        roads[c2]->push_back(r2);
    }

    if (spfa(scity)) {
        cout << dis[ecity] << endl;
    }

    return 0;
}