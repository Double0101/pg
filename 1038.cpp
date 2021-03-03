#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &s1, string &s2)
{
    return s1+s2 < s2+s1;
}
vector<string> ss;
int N;
int main()
{
    cin >> N;
    ss.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> ss[i];
    }
    sort(ss.begin(), ss.end(), cmp);
    string ans = "";
    for (int i = 0; i < N; ++i) {
        ans += ss[i];
    }
    ans.erase(0, ans.find_first_not_of('0'));
    if (ans.length() == 0) ans = "0";
    cout << ans << endl;
    return 0;
}
