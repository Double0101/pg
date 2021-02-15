#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visit[1001];
queue<int> q;

int findFollow(vector<vector<int>> &f, int level, int user)
{
    fill(visit, visit+1001, false);
    q.push(user);
    int l = 0, count = -1;
    while (l < level && !q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            int n = q.front();
            q.pop();
            if (visit[n] == false) {
                ++count;
                visit[n] = true;
                for (int j = 0; j < f[n].size(); ++j) {
                    q.push(f[n][j]);
                }
            }
        }
        ++l;
    }
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (visit[n] == false) {
            ++count;
            visit[n] = true;
        }
    }
    return count;
}

int main()
{
    int N, L, K, I;
    scanf("%d%d", &N, &L);
    vector<vector<int>> followers(N+1);
    for (int i = 1; i <= N; ++i) {
        int a, b;
        scanf("%d", &a);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &b);
            followers[b].push_back(i);
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &I);
        printf("%d\n", findFollow(followers, L, I));
    }
    return 0;
}