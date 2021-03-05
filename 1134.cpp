#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> m;
int Nv, Ne;
int arr[10000];
bool visit[10000];
int main()
{
    scanf("%d%d", &Nv, &Ne);
    m.resize(Nv);
    int a, b;
    for (int i = 0; i < Ne; ++i) {
        scanf("%d%d", &a, &b);
        m[a].push_back(i);
        m[b].push_back(i);
    }
    int Q, n;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &n);
        fill(visit, visit+Ne, 0);
        for (int j = 0; j < n; ++j) {
            scanf("%d", arr+j);
            for (int k : m[arr[j]]) {
                visit[k] = 1;
            }
        }
        int flag = 1;
        for (int j = 0; j < Ne; ++j) {
            if (visit[j] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
