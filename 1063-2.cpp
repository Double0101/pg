#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
    vector<set<int>> m;
    int N, n;
    scanf("%d", &N);
    m.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &n);
        int a;
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            m[i].insert(a);
        }
    }
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &a, &b);
        set<int> ss;
        ss.insert(m[a-1].begin(), m[a-1].end());
        ss.insert(m[b-1].begin(), m[b-1].end());
        int sb = ss.size();
        printf("%.1lf%%\n", (m[b-1].size()-sb+m[a-1].size())*100.0/sb);
    }
    return 0;
}
