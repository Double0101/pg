#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int s1, int s2)
{
    return s1 < s2;
}
const int maxn = 26*26*26*10;
string names[maxn];

int getid(string s)
{
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        id = id * 26 + s[i] - 'A';
    }
    id = id * 10 + s[3] - '0';
    return id;
}

int main()
{
    int sn, cn;
    cin >> sn >> cn;
    vector<int> namelist[cn];
    for (int i = 0; i < sn; ++i) {
        string name;
        int a, b;
        cin >> name >> a;
        int id = getid(name);
        names[id] = name;
        for (int j = 0; j < a; ++j) {
            cin >> b;
            namelist[b-1].push_back(id);
        }
    }
    for (int i = 0; i < cn; ++i) {
        cout << i+1 << " " << namelist[i].size() << endl;
        sort(namelist[i].begin(), namelist[i].end(), cmp);
        for (int s : namelist[i]) {
            cout << names[s] << endl;
        }
    }
    return 0;
}