#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

bool isPrime(int a)
{
    if (a == 0 || a == 1) return false;
    int end = sqrt(a);
    for (int i = 2; i <= end; ++i) {
        if (a%i == 0) return false;
    }
    return true;
}

int main()
{
    int N, M;
    string num;
    cin >> N >> M;
    cin >> num;
    for (int i = 0; i <= N - M; ++i) {
        string s = num.substr(i, M);
        if (isPrime(stoi(s))) {
            cout << s << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
