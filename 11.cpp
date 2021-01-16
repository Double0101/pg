#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct node{
    int name, best;
    int score[4], rank[4];
} node;
int exists[1000000] = {0};
int flag = -1;
bool cmp(node n1, node n2) {
    return n1.score[flag] > n2.score[flag];
}
node stu[2001];
int N, M;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        scanf("%d %d %d %d", &stu[i].name,
              &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        stu[i].score[3] = (stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
    }
    for (int i = 0; i < 4; ++i) {
        flag = i;
        node *s = stu+1;
        sort(s, s+N, cmp);
        stu[1].rank[i] = 1;
        for (int j = 2; j <= N; ++j) {
            if (stu[j].score[i] == stu[j-1].score[i])
                stu[j].rank[i] = stu[j-1].rank[i];
            else
                stu[j].rank[i] = j;
        }
    }
    int ol[4] = {3,0,1,2};
    for (int i = 1; i <= N; ++i) {
        exists[stu[i].name] = i;
        int o = M+1;
        for (int j = 0; j < 4; ++j) {
            if (stu[i].rank[ol[j]] < o) {
                o = stu[i].rank[ol[j]];
                stu[i].best = ol[j];
            }
        }
    }
    char sl[4] = {'C', 'M', 'E', 'A'};
    for (int i = 0; i < M; ++i) {
        int id;
        scanf("%d", &id);
        if (exists[id] == 0) printf("N/A\n");
        else {
            int o = exists[id];
            printf("%d %c\n", stu[o].rank[stu[o].best], sl[stu[o].best]);
        }
    }
    return 0;
}