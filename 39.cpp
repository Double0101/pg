#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool cmp(int i1, int i2)
{
    return i1 < i2;
}

int getid(string name)
{
    int id = 0;
    for (int i = 0; i < name.length()-1; ++i) {
        id = id*26 + name[i]-'A';
    }
    id = id*10 + name[name.length()-1] - '0';
    return id;
}
const int maxn = 26*26*26*10+10;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> courses[maxn];
    int num = 0;
    for (int i = 0; i < K; ++i) {
        int course, snum;
        cin >> course >> snum;
        for (int j = 0; j < snum; ++j) {
            string s;
            cin >> s;
            courses[getid(s)].push_back(course);
        }
    }
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        int index = getid(name);
        sort(courses[index].begin(), courses[index].end(), cmp);
        cout << name << " " << courses[index].size();
        for (int c : courses[index]) {
            cout << " " << c;
        }
        cout << endl;
    }

    return 0;
}