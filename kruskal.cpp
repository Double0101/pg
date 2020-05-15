#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Edge {
    int v1, v2, cost;
} Edge;

int citynum, roadnum;
int *FA;

Edge **egco;

bool ecmp(void *e1, void *e2)
{
    return (((Edge*)e1)->cost) < (((Edge*)e2)->cost);
}

int findfather(int son) {
    int x = son;
    while (son != FA[son]) {
        son = FA[son];
    }
    while (x != FA[x]) {
        int s = x;
        x = FA[x];
        FA[s] = son;
    }
    return son;
}

int kruskal()
{
    int ans = 0;
    int es = 0;
    sort(egco, egco + roadnum, ecmp);
    for (int i = 0; i < roadnum; ++i) {
        Edge* cure = egco[i];
        int fa, fb;
        fa = findfather(cure->v1);
        fb = findfather(cure->v2);
        if (fa == fb) continue;
        ans += cure->cost;
        FA[fa] = fb;
        cout << cure->v1 << " " << cure->v2 << " " << cure->cost << endl;
        ++es;
        if (es == citynum - 1)
            break;
    }
    return (es == citynum -1) ? ans : -1;
}

int main()
{
    cin >> citynum >> roadnum;
    egco = (Edge**) malloc(sizeof(Edge*) * roadnum);
    for (int i = 0; i < roadnum; ++i) {
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        Edge *e = (Edge*) malloc(sizeof(Edge));
        e->v1 = c1;
        e->v2 = c2;
        e->cost = len;
        egco[i] = e;
    }
    FA = (int*) malloc(sizeof(int) * citynum);
    for (int j = 0; j < citynum; ++j) {
        FA[j] = j;
    }

    cout << kruskal() << endl;
    return 0;
}