#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2)
{
    return s1 + s2 < s2 + s1;
}

int main()
{
    int N;
    cin >> N;
    vector<string> slib(N);
    for (int i = 0; i < N; ++i) {
        cin >> slib[i];
    }
    sort(slib.begin(), slib.end(), cmp);
    string s = "";
    for (int i = 0; i < N; ++i) {
        s += slib[i];
    }
    s.erase(0, s.find_first_not_of('0'));
    if (s.length() == 0) s = "0";
    cout << s << endl;
    return 0;
}
