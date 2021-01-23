#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void add(string &s1, string &s2) {
    int len = s1.length();
    int carry = 0;
    for (int i = 0; i < len; ++i) {
        s1[i] = s1[i] + s2[i] + carry - '0';
        carry = 0;
        if (s1[i] > '9') {
            carry = 1;
            s1[i] -= 10;
        }
    }
    if (carry == 1) s1 += '1';
    reverse(s1.begin(), s1.end());
}

int main()
{
    string s, t;
    int maxstep;
    cin >> s >> maxstep;
    int step;
    for (step = 0; step <= maxstep; ++step) {
        t = s;
        reverse(t.begin(), t.end());
        if (s == t || step == maxstep) break;
        add(s, t);
    }

    cout << s << endl;
    cout << step << endl;

    return 0;
}