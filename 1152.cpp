#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1) return false;
    int end = sqrt(n);
    for (int i = 2; i <= end; ++i) {
        if (n%i == 0) return false;
    }
    return true;
}

int main()
{
    int L, K, num;
    string s, sub;
    cin >> L >> K;
    cin>> s;
    int len = s.length();
    for (int i = 0; i <= len-K; ++i) {
        sub = s.substr(i, K);
        sscanf(sub.c_str(), "%d", &num);
        if (isPrime(num)) {
            cout << sub << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}