#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Applicant {
    int id, GE, GI, total, rank;
    int choices[5];
} Apt;

bool cmp(Apt a1, Apt a2)
{
    if (a1.total != a2.total) return a1.total > a2.total;
    return a1.GE > a2.GE;
}
bool cmp1(int a, int b) { return a < b; }

int main()
{
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    vector<int> quota(M);
    vector<Apt> apts(N);
    vector<vector<int>> entail(M);
    vector<int> entailrank(M, -1);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &(apts[i].GE), &(apts[i].GI));
        apts[i].total = apts[i].GE+apts[i].GI;
        apts[i].id = i;
        for (int j = 0; j < K; ++j) {
            scanf("%d", &(apts[i].choices[j]));
        }
    }
    sort(apts.begin(), apts.end(), cmp);
    apts[0].rank = 0;
    for (int i = 1; i < N; ++i) {
        if (apts[i].total == apts[i-1].total
            && apts[i].GE == apts[i-1].GE)
            apts[i].rank = apts[i-1].rank;
        else apts[i].rank = i;
    }
    for (int i = 0; i < N; ++i) {
        int flag = 0;
        for (int j = 0; j < K; ++j) {
            int school = apts[i].choices[j];
            if (entail[school].size() < quota[school]
                || apts[i].rank == entailrank[school]) {
                entail[school].push_back(apts[i].id);
                entailrank[school] = apts[i].rank;
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
    }
    for (int i = 0; i < M; ++i) {
        if (!entail[i].empty()) {
            sort(entail[i].begin(), entail[i].end(), cmp1);
            printf("%d", entail[i][0]);
            for (int j = 1; j < entail[i].size(); ++j) {
                printf(" %d", entail[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
