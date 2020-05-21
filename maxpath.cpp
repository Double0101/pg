#define MAX 100
#include <iostream>

using namespace std;

typedef struct N {
    int max = 0, data;
} N;

N pa[MAX][MAX];
int crow;

int main()
{
    cin >> crow;
    for (int i = 0; i < crow; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> pa[i][j].data;
        }
    }

    pa[0][0].max = pa[0][0].data;
    for (int k = 0; k < crow - 1; ++k) {
        for (int i = 0; i <= k; ++i) {
            if (pa[k+1][i].max < pa[k+1][i].data + pa[k][i].max) {
                pa[k+1][i].max = pa[k+1][i].data + pa[k][i].max;
            }
            if (pa[k+1][i+1].max < pa[k+1][i+1].data + pa[k][i].max) {
                pa[k+1][i+1].max = pa[k+1][i+1].data + pa[k][i].max;
            }
        }
    }

    int r = crow - 1;
    for (int l = 0; l < crow; ++l) {
        cout << pa[r][l].max << " ";
    }
    cout << endl;
    return 0;
}
