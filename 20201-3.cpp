#include <cstdio>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> neighbor;
int K, N, R, M;
int main()
{
    scanf("%d%d%d", &N, &R, &K);
    neighbor.resize(N+1);
    int a, b;
    for (int i = 0; i < R; ++i) {
        scanf("%d%d", &a, &b);
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }
    scanf("%d", &M);
    vector<int> animal(N+1);
    for (int i = 0; i < M; ++i) {
        set<int> as;
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &(animal[j]));
            as.insert(animal[j]);
        }
        if (as.size() > K) {
            printf("Error: Too many species.\n");
        } else if (as.size() < K) {
            printf("Error: Too few species.\n");
        } else {
            int flag = 1;
            for (int j = 1; j <= N && flag == 1; ++j) {
                for (int k : neighbor[j]) {
                    if (animal[k] == animal[j]) {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
