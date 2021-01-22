#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int N;
vector<vector<int>> m(10001);
bool visit[10001];
int mmax;
set<int> startset, tempset;

void dfs(int start, int level, set<int> &ss)
{
    if (visit[start] == true) return;
    ++level;
    visit[start] = true;
    if (level > mmax) {
        mmax = level;
        ss.clear();
        ss.insert(start);
    } else if (level == mmax) {
        ss.insert(start);
    }
    for (int i : m[start]) {
        dfs(i, level, ss);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    int time = 0;
    fill(visit+1, visit+N+1, false);
    for (int i = 1; i <= N; ++i) {
        if (visit[i] == true) continue;
        ++time;
        mmax = 0;
        dfs(i, 0, tempset);
    }
    if (time > 1) {
        printf("Error: %d components", time);
        return 0;
    }
    startset.insert(tempset.begin(), tempset.end());
    tempset.clear();
    mmax = 0;
    fill(visit+1, visit+N+1, false);

    dfs(*startset.begin(), 0, tempset);
    startset.insert(tempset.begin(), tempset.end());
    for (int i : startset) {
        printf("%d\n", i);
    }
    return 0;
}