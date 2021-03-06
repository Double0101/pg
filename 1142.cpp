#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, bool> adj;
int arr[300];
int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &a, &b);
        adj[a*1000+b] = adj[b*1000+a] = true;
    }
    int Q, n, clique, max, visit[300];
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        fill(visit, visit+300, 0);
        clique = max = 1;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", arr+j);
            visit[arr[j]] = 1;
            for (int k = j-1; k >= 0 && clique == 1; --k) {
                if (adj[arr[j]*1000+arr[k]] == false) clique = 0;
            }
        }
        for (int j = 1; j <= N && clique == 1; ++j) {
            int flag = 1;
            if (visit[j] == 1) continue;
            for (int k = 0; k < n && flag == 1; ++k) {
                if (adj[j*1000+arr[k]] != true) flag = 0;
            }
            if (flag == 1) {
                max = 0;
                break;
            }
        }
        if (clique == 0) printf("Not a Clique\n");
        else if (max == 1) printf("Yes\n");
        else printf("Not Maximal\n");
    }
    return 0;
}