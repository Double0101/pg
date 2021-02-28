#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int N, M, flag;
int color[10000];
vector<pair<int, int>> edges;
int main()
{
    scanf("%d%d", &N, &M);
    edges.resize(M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &(edges[i].first), &(edges[i].second));
    }
    int Q;
    set<int> cset;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        cset.clear();
        flag = 1;
        for (int i = 0; i < N; ++i) {
            scanf("%d", color+i);
            cset.insert(color[i]);
        }
        for (int j = 0; j < M; ++j) {
            if (color[edges[j].first] == color[edges[j].second]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) printf("%d-coloring\n", cset.size());
        else printf("No\n");
    }
    return 0;
}
