#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef struct testee {
    string id;
    int score, local;
    int frank, lrank;
} testee;

const int MAXN = 30000;
vector<testee> ees(MAXN);

bool cmp(testee t1, testee t2)
{
    if (t1.score > t2.score) return true;
    if (t1.score == t2.score && t1.id < t2.id) return true;
    return false;
}

int N, mc[100];

int main()
{
    int total = 0;
    scanf("%d", &N);
    int st, et = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d\n", mc+i);
        total += mc[i];
        st = et;
        for (int j = 0; j < mc[i]; ++j) {
            cin >> ees[et].id >> ees[et].score;
            ees[et].local = i+1;
            ++et;
        }
        sort(ees.begin()+st, ees.begin()+et, cmp);
        int s = ees[st].score;
        ees[st].lrank = 1;
        for (int j = st+1; j < et; ++j) {
            if (ees[j].score == s) ees[j].lrank = ees[j-1].lrank;
            else {
                s = ees[j].score;
                ees[j].lrank = j-st+1;
            }
        }
    }
    sort(ees.begin(), ees.begin()+total, cmp);

    int s = ees[0].score;
    ees[0].frank = 1;
    for (int i = 1; i < total; ++i) {
        if (ees[i].score == s) ees[i].frank = ees[i-1].frank;
        else {
            s = ees[i].score;
            ees[i].frank = i+1;
        }
    }

    cout << total << endl;

    for (int i = 0; i < total; ++i) {
        cout << ees[i].id << " " << ees[i].frank << " "
            << ees[i].local << " " << ees[i].lrank << endl;
    }

    return 0;
}