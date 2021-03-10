#include <vector>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, vector<int>> m;
int N, M, inside[100000];
int main()
{
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int flag;
    for (int i = 0; i < M; ++i) {
        scanf("%d", &N);
        vector<int> package(N);
        flag = 1;
        fill(inside, inside+100000, 0);
        for (int j = 0; j < N; ++j) {
            scanf("%d", &(package[j]));
            inside[package[j]] = 1;
        }
        for (int j = 0; j < N && flag == 1; ++j) {
            for (int k : m[package[j]]) {
                if (inside[k] == 1) {
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
