#include <iostream>
#include <climits>

using namespace std;

int P[6][6] = {
        {      0,       1, INT_MAX,       4,       4, INT_MAX},
        {INT_MAX,       0, INT_MAX,       2, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX,       0, INT_MAX, INT_MAX,       1},
        {INT_MAX, INT_MAX,       2,       0,       3, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX,       0,       3},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,       0},
};

bool visited[6] = {false};
int dis[6] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};

void dijkstra(int s)
{
    dis[s] = 0;
    for (int i = 0; i < 6; ++i) {
        int min = INT_MAX; int u = -1;
        for (int j = 0; j < 6; ++j) {
            if (!visited[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }

        if (u == -1) return;
        visited[u] = true;
        for (int k = 0; k < 6; ++k) {
            if (!visited[k] && P[u][k] < INT_MAX && dis[k] > dis[u] + P[u][k]) {
                dis[k] = dis[u] + P[u][k];
            }
        }
    }
}

int main()
{
    dijkstra(0);
    for (int i = 0; i < 6; ++i) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}