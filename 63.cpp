#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int N, qn;
    scanf("%d", &N);
    vector<set<int>> sv(N+1);
    for (int i = 1; i <=  N; ++i) {
        int n, a;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            sv[i].insert(a);
        }
    }
    scanf("%d", &qn);
    for (int i = 0; i < qn; ++i) {
        int s1, s2, count = 0;
        scanf("%d%d", &s1, &s2);
        for (int sc : sv[s1]) {
            if (sv[s2].find(sc) == sv[s2].end()) {
                ++count;
            }
        }
        int total = count + sv[s2].size();
        int com = sv[s1].size() - count;
        double r = com*100.0/total;
        printf("%.1f%%\n", r);
    }
    return 0;
}
