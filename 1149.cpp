#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, vector<int>> m;
int main()
{
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int set[1000], flag;
    for (int i = 0; i < M; ++i) {
        scanf("%d", &N);
        flag = 1;
        vector<int> mm(100000, 0);
        for (int j = 0; j < N; ++j) {
            scanf("%d", set+j);
            mm[set[j]] = 1;
        }
        for (int j = 0; j < N && flag == 1; ++j) {
            for (int k : m[set[j]]) {
                if (mm[k] == 1) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
