#include <cstdio>
#include <iostream>
#include <vector>
#define M true
#define F false

using namespace std;

typedef struct Student {
    string name;
    string id;
    int grade;
    bool gender;
} stu;

int main()
{
    int N;
    cin >> N;
    stu m, f, t;
    m.grade = 101, f.grade = -1;
    for (int i = 0; i < N; ++i) {
        char g;
        cin >> t.name >> g >> t.id >> t.grade;
        if (g == 'M') t.gender = M;
        else t.gender = F;
        if (t.gender == M) {
            if (t.grade < m.grade) m = t;
        } else {
            if (t.grade > f.grade) f = t;
        }
    }
    int flag = 0;
    if (f.grade == -1) {
        flag = 1;
        cout << "Absent" << endl;
    } else {
        cout << f.name << " " << f.id << endl;
    }
    if (m.grade == 101) {
        flag = 1;
        cout << "Absent" << endl;
    } else {
        cout << m.name << " " << m.id << endl;
    }

    if (flag == 1) cout << "NA" << endl;
    else cout << f.grade-m.grade << endl;
    return 0;
}