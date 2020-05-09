#include <iostream>
#include <queue>

#define P2INDEX(a) (a-1)

using namespace std;

int **W;
bool *visited;
int num;
int tier;

queue<int> fnet;

int subscribe(int index)
{
    int pc = 0;
    visited[index] = true;
    fnet.push(index);
    for (int i = 0; i < tier; ++i) {
        int ss = fnet.size();
        for (int j = 0; j < ss; ++j) {
            int ii = fnet.front();
            fnet.pop();
            ++pc;
            for (int k = 0; k < num; ++k) {
                if (W[ii][k] && !visited[k]) {
                    visited[k] = true;
                    fnet.push(k);
                }
            }
        }
    }

    while (!fnet.empty()) {
        fnet.pop();
        ++pc;
    }
    return pc-1;
}

int main()
{
    cin >> num >> tier;
    W = (int**) malloc(sizeof(int*) * num);
    visited = (bool*) malloc(sizeof(bool) * num);
    for (int i = 0; i < num; ++i) {
        W[i] = (int*) malloc(sizeof(int) * num);
        memset(W[i], 0, sizeof(int) * num);
    }
    for (int j = 0; j < num; ++j) {
        int cc, dd;
        cin >> cc;
        for (int i = 0; i < cc; ++i) {
            cin >> dd;
            W[P2INDEX(dd)][j] = 1;
        }
    }

    int anum, *pl, in;
    cin >> anum;
    pl = (int*) malloc(sizeof(int) * anum);
    for (int k = 0; k < anum; ++k) {
        cin >> in;
        pl[k] = P2INDEX(in);
    }

    for (int l = 0; l < anum; ++l) {
        memset(visited, 0, sizeof(bool) * num);
        cout << subscribe(pl[l]) << endl;
    }

    return 0;
}