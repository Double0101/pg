#include <cstdio>
#include <set>
#include <vector>
using namespace std;
vector<set<int>> iset;
int N;
int main()
{
    scanf("%d", &N);
    iset.resize(N+1);
    int a, b, c;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &a);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &b);
            iset[i].insert(b);
        }
    }
    scanf("%d", &a);
    for (int i = 0; i < a; ++i) {
        scanf("%d%d", &b, &c);
        int count = 0;
        for (int j : iset[c]) {
            if (iset[b].find(j) == iset[b].end())
                ++count;
        }
        printf("%.1lf%%\n", (iset[c].size()-count)*1.0/(count+iset[b].size())*100);
    }
    return 0;
}
