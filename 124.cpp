#include <cstdio>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int M, N, S;
    cin >> M >> N >> S;
    string name;
    set<string> wirset;
    int wm = S%N;
    for (int i = 1; i <= M; ++i) {
        cin >> name;
        if (i >= S && i%N == wm) {
            if (wirset.find(name) == wirset.end()) {
                cout << name << endl;
                wirset.insert(name);
            } else {
                ++S;
                wm = S%N;
            }
        }
    }
    if (wirset.empty()) printf("Keep going...\n");
    return 0;
}
