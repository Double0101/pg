#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> n2index;
int calltime[2000];
int gangtime[2000];
int gangc[2000];
string i2n[2000];
int father[2000];

bool cmp(int i1, int i2)
{
    return i2n[i1] < i2n[i2];
}

int Father(int i1)
{
    int a = i1;
    while (father[a] != a) {
        a = father[a];
    }
    int fa = a;
    a = i1;
    while (a != fa) {
        int temp = father[a];
        father[a] = fa;
        a = temp;
    }
    return fa;
}

void Union(int i1, int i2)
{
    int f1 = Father(i1), f2 = Father(i2);
    if (f1 != f2) father[f2] = f1;
}

int n2i(string &s)
{
    auto it = n2index.find(s);
    if (it == n2index.end()) return -1;
    return it->second;
}

int main()
{
    fill(calltime, calltime+2000, 0);
    fill(gangtime, gangtime+2000, 0);
    fill(gangc, gangc+2000, 0);
    fill(father, father+2000, 0);
    int cnum, threshold;
    cin >> cnum >> threshold;
    int num = 0;
    for (int i = 0; i < cnum; ++i) {
        string s1, s2;
        int t;
        cin >> s1 >> s2 >> t;
        int i1 = n2i(s1);
        int i2 = n2i(s2);
        if (i1 == -1) {
            n2index[s1] = num;
            i1 = num++;
            father[i1] = i1;
            i2n[i1] = s1;
        }
        if (i2 == -1) {
            n2index[s2] = num;
            i2 = num++;
            father[i2] = i2;
            i2n[i2] = s2;
        }
        calltime[i1] += t;
        calltime[i2] += t;
        Union(i1, i2);
    }
    vector<int> gang;
    for (int i = 0; i < num; ++i) {
        int fi = Father(i);
        if (fi == i) gang.push_back(i);
        gangtime[fi] += calltime[i];
        ++gangc[fi];
    }
    sort(gang.begin(), gang.end(), cmp);
    int count = 0;
    for (int i = 0; i < gang.size(); ++i) {
        if ((gangtime[gang[i]] > (threshold*2)) && gangc[gang[i]] > 2) ++count;
    }
    cout << count <<endl;
    for (int i = 0; i < gang.size(); ++i) {
        if (gangtime[gang[i]] > (threshold*2) && gangc[gang[i]] > 2) {
            int max = 0, fa = gang[i], gh;
            for (int j = 0; j < num; ++j) {
                if (Father(j) == fa) {
                    if (calltime[j] > max) {
                        max = calltime[j];
                        gh = j;
                    }
                }
            }
            cout << i2n[gh] << " " << gangc[gang[i]] << endl;
        }
    }
    return 0;
}