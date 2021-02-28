#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef struct Student {
    int score, site, date, id;
    char level;
    string cardn;
} stu;
bool cmp1(stu &s1, stu &s2)
{
    return s1.score == s2.score ? s1.cardn < s2.cardn : s1.score > s2.score;
}
int N, M, snum[1000];
bool cmp2(int &s1, int &s2)
{
    return snum[s1] == snum[s2] ? s1 < s2 : snum[s1] > snum[s2];
}
vector<stu> stus;
int main()
{
    cin >> N >> M;
    stus.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> stus[i].cardn >> stus[i].score;
        stus[i].level = stus[i].cardn[0];
        stus[i].site = stoi(stus[i].cardn.substr(1, 3));
        stus[i].date = stoi(stus[i].cardn.substr(4, 6));
        stus[i].id = stoi(stus[i].cardn.substr(10, 3));
    }
    int type, nnn, result;
    string l;
    for (int i = 1; i <= M; ++i) {
        result = 0;
        cin >> type >> l;
        cout << "Case " << i << ": " << type;
        if (type == 1) {
            vector<stu> ans;
            cout << " " << l << endl;
            for (int j = 0; j < N; ++j) {
                if (stus[j].level == l[0]) {
                    ans.push_back(stus[j]);
                    ++result;
                }
            }
            sort(ans.begin(), ans.end(), cmp1);
            for (int j = 0; j < ans.size(); ++j) {
                cout << ans[j].cardn << " " << ans[j].score << endl;
            }
        } else {
            nnn = stoi(l);
            cout << " " << l << endl;
            if (type == 2) {
                int total = 0, sn = 0;
                for (int j = 0; j < N; ++j) {
                    if (stus[j].site == nnn)
                        ++total, sn += stus[j].score, ++result;
                }
                if (total != 0)
                    cout << total << " " << sn << endl;
            } else {
                vector<int> ss;
                fill(snum, snum+1000, 0);
                for (int j = 0; j < N; ++j) {
                    if (stus[j].date == nnn) {
                        if (snum[stus[j].site] == 0)
                            ss.push_back(stus[j].site);
                        ++snum[stus[j].site];
                        ++result;
                    }
                }
                sort(ss.begin(), ss.end(), cmp2);
                for (int j : ss) {
                    cout << j << " " << snum[j] << endl;
                }
            }
        }
        if (result == 0) cout << "NA" << endl;
    }
    return 0;
}
