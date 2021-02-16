#include <cstdio>
#include <vector>

using namespace std;

typedef struct student {
    char name[15], ID[15];
    int grade;
} stu;

int main()
{
    int N;
    scanf("%d", &N);
    vector<stu> stus(N);
    vector<int> map(101, -1);
    for (int i = 0; i < N; ++i) {
        scanf("%s %s %d", stus[i].name, stus[i].ID, &(stus[i].grade));
        map[stus[i].grade] = i;
    }
    int a, b, count = 0;
    scanf("%d%d", &a, &b);
    for (int i = b; i >= a; --i) {
        if (map[i] == -1) continue;
        printf("%s %s\n", stus[map[i]].name, stus[map[i]].ID);
        ++count;
    }
    if (count == 0) printf("NONE\n");
    return 0;
}