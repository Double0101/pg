#include <iostream>
#include <climits>


using namespace std;

int citynum, roadnum;

int **dis;

void floyd()
{
    for (int i = 0; i < citynum; ++i) {
        for (int j = 0; j < citynum; ++j) {
            for (int k = 0; k < citynum; ++k) {
                if (dis[j][i] != INT_MAX
                    && dis[i][k] != INT_MAX
                    && dis[j][k] > dis[j][i] + dis[i][k]) {
                    dis[j][k] = dis[j][i] + dis[i][k];
                }
            }
        }
    }
}

int main()
{
    cin >> citynum >> roadnum;
    dis = (int**) malloc(sizeof(int*) * citynum);
    for (int i = 0; i < citynum; ++i) {
        dis[i] = (int*) malloc(sizeof(int) * citynum);
        int* di = dis[i];
        fill(di, di + citynum, INT_MAX);
        di[i] = 0;
    }

    for (int j = 0; j < roadnum; ++j) {
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        dis[c1][c2] = len;
//        dis[c2][c1] = len;
    }

    floyd();

    for (int k = 0; k < citynum; ++k) {
        for (int i = 0; i < citynum; ++i) {
            cout << dis[k][i] << " ";
        }
        cout << endl;
    }
    return 0;
}