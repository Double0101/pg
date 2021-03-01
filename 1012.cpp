#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Student {
    int id, grade[4], rank[4];
} stu;
int target = 0;
bool cmp(const stu &s1, const stu &s2) {
    return s1.grade[target] > s2.grade[target];
}
int N, Q;
int index[1000000] = {0};
vector<stu> stus;
int main()
{
    scanf("%d%d", &N, &Q);
    stus.resize(N);
    fill(index, index+1000000, -1);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", &(stus[i].id), stus[i].grade+1,
              stus[i].grade+2, stus[i].grade+3);
        stus[i].grade[0] = (stus[i].grade[1]+stus[i].grade[2]+stus[i].grade[3])/3;
    }
    for (target = 0; target < 4; ++target) {
        sort(stus.begin(), stus.end(), cmp);
        stus[0].rank[target] = 1;
        for (int i = 1; i < N; ++i) {
            if (stus[i].grade[target] == stus[i-1].grade[target])
                stus[i].rank[target] = stus[i-1].rank[target];
            else stus[i].rank[target] = i+1;
        }
    }
    for (int i = 0; i < N; ++i) {
        index[stus[i].id] = i;
    }
    int qi;
    char label[4] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &qi);
        if (index[qi] == -1) printf("N/A\n");
        else {
            int mini = -1, minr = N, idx = index[qi];
            for (int j = 0; j < 4; ++j) {
                if (stus[idx].rank[j] < minr) {
                    minr = stus[idx].rank[j];
                    mini = j;
                }
            }
            printf("%d %c\n", stus[idx].rank[mini], label[mini]);
        }
    }
    return 0;
}
