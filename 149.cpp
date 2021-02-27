#include <unordered_map>
#include <cstdio>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> m;
int N, M;
int l1, l2;
int list[1000];
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &l1, &l2);
        m[l1].push_back(l2);
        m[l2].push_back(l1);
    }
    for (int i = 0; i < M; ++i) {
        int n, flag = 1;
        int mm[100000] = {0};
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", list+j);
            mm[list[j]] = 1;
        }
        for (int j = 0; flag == 1 && j < n-1; ++j) {
            for (int k : m[list[j]]) {
                if (mm[k] == 1) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}