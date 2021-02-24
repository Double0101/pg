#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Query {
    int q, count;
    Query(int a, int b) : q(a), count(b) {}
} query;

bool cmp(query q1, query q2) {
    if (q1.count == q2.count) return q1.q < q2.q;
    return q1.count > q2.count;
}
vector<query> qs;

int main() {
    int N, K, qq;
    scanf("%d%d", &N, &K);
    vector<int> visit(N+1, 0);
    scanf("%d", &qq);
    qs.emplace_back(qq, 1);
    ++visit[qq];
    for (int i = 1; i < N; ++i) {
        scanf("%d", &qq);
        printf("%d:", qq);
        for (int j = 0; j < K && j < qs.size(); ++j) {
            printf(" %d", qs[j].q);
        }
        printf("\n");
        ++visit[qq];
        int idx = 0;
        while (qs[idx].q != qq && idx < qs.size()) ++idx;
        if (idx == qs.size()) qs.emplace_back(qq, 0);
        qs[idx].count = visit[qq];
        sort(qs.begin(), qs.end(), cmp);
        if (qs.size() > K) qs.pop_back();
    }
    return 0;
}
