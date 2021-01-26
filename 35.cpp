#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char, char> mm;

bool inmap(char c) {
    auto it = mm.find(c);
    if (it == mm.end()) return false;
    return true;
}

int main()
{
    mm['1'] = '@';
    mm['0'] = '%';
    mm['l'] = 'L';
    mm['O'] = 'o';
    int N;
    cin >> N;
    vector<bool> modify(N);
    vector<string> name(N);
    vector<string> password(N);
    for (int i = 0; i < N; ++i) {
        cin >> name[i] >> password[i];
        modify[i] = false;
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
        string pwd = password[i];
        bool flag = false;
        for (int j = 0; j < pwd.size(); ++j) {
            if (inmap(pwd[j])) {
                pwd[j] = mm[pwd[j]];
                flag = true;
            }
        }
        modify[i] = flag;
        if (flag) {
            count += 1;
            password[i] = pwd;
        }
    }
    if (count == 0) {
        if (N > 1) {
            cout << "There are " << N << " accounts and no account is modified" << endl;
            return 0;
        }
        cout << "There is 1 account and no account is modified" << endl;
        return 0;
    }
    cout << count << endl;
    for (int i = 0; i < N; ++i) {
        if (modify[i]) {
            cout << name[i] << ' ' << password[i] << endl;
        }
    }

    return 0;
}