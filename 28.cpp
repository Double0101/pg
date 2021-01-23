#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef struct student {
    int id;
    string name;
    int grade;
} stu;

bool cmp1(stu stu1, stu stu2)
{
    return stu1.id < stu2.id;
}
bool cmp2(stu stu1, stu stu2)
{
    if (stu1.name < stu2.name) return true;
    if (stu1.name == stu2.name && stu1.id < stu2.id) return true;
    return false;
}
bool cmp3(stu stu1, stu stu2)
{
    if (stu1.grade < stu2.grade) return true;
    if (stu1.grade == stu2.grade && stu1.id < stu2.id) return true;
    return false;
}

int N, C;
stu sl[100000];

int main()
{
    scanf("%d%d\n", &N, &C);
    for (int i = 0; i < N; ++i) {
        cin >> sl[i].id >> sl[i].name >> sl[i].grade;
    }
    bool (*cmp[4])(stu, stu);
    cmp[1] = cmp1;
    cmp[2] = cmp2;
    cmp[3] = cmp3;
    sort(sl, sl+N, cmp[C]);
    for (int i = 0; i < N; ++i) {
        printf("%06d %s %d\n", sl[i].id, sl[i].name.c_str(), sl[i].grade);
    }
}