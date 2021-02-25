#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m[205][205];
int hsh[205];

int main()
{
    int Nv, Ne, a, b;
    scanf("%d%d", &Nv, &Ne);
    for (int i = 0; i < Ne; ++i) {
        scanf("%d%d", &a, &b);
        m[a][b] = m[b][a] = 1;
    }
    int Q, n, flag;
    scanf("%d", &Q);
    vector<int> set;
    for (int i = 0; i < Q; ++i) {
        set.clear();
        fill(hsh, hsh+205, 0);
        flag = 1;
        scanf("%d", &n);
        set.resize(n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &(set[j]));
            hsh[set[j]] = 1;
        }

        for (int j = 0; flag == 1 && j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (m[set[j]][set[k]] != 1) {
                    flag = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (flag == 0) continue;
        for (int j = 1; j <= Nv; ++j) {
            if (hsh[j] == 0) {
                flag = 0;
                for (int k = 0; k < n; ++k) {
                    if (m[j][set[k]] == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    printf("Not Maximal\n");
                    break;
                }
            }
        }
        if (flag == 1) printf("Yes\n");
    }

    return 0;
}