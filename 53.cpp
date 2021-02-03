#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> childrens;
vector<int> weights;
vector<int> p;

bool cmp(int r1, int r2) {
    return weights[r1] > weights[r2];
}

void dfs(int root, int &ww, const int desw, vector<int> &path)
{
    path.push_back(root);
    ww += weights[root];
    for (int i = 0; i < childrens[root].size(); ++i) {
        dfs(childrens[root][i], ww, desw, path);
    }
    if (childrens[root].empty() && ww == desw) {
        printf("%d", weights[path[0]]);
        for (int i = 1; i < path.size(); ++i) {
            printf(" %d", weights[path[i]]);
        }
        printf("\n");
    }
    ww -= weights[root];
    path.pop_back();
}

int main()
{
    int N, M, W;
    scanf("%d %d %d", &N, &M, &W);
    childrens.resize(N);
    weights.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(weights[i]));
    }
    for (int i = 0; i < M; ++i) {
        int rot, num, n;
        scanf("%d %d", &rot, &num);
        for (int j = 0; j < num; ++j) {
            scanf("%d", &n);
            childrens[rot].push_back(n);
        }
        sort(childrens[rot].begin(), childrens[rot].end(), cmp);
    }
    int www = 0;
    dfs(0, www, W, p);
    return 0;
}