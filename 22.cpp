#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

map<string, set<int>> namem;
map<string, set<int>> keywordm;
map<string, set<int>> authorm;
map<string, set<int>> publisherm;
map<string, set<int>> yearm;

int N;

void print(map<string, set<int>> &m, string str)
{
    if (m.find(str) != m.end()) {
        for (int i : m[str]) {
            printf("%07d\n", i);
        }
    } else {
        printf("Not Found\n");
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int id;
        scanf("%d\n", &id);
        string name, author, publisher, keywords, year;
        getline(cin, name);
        namem[name].insert(id);
        getline(cin, author);
        authorm[author].insert(id);
        while (cin >> keywords) {
            keywordm[keywords].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }
        getline(cin, publisher);
        publisherm[publisher].insert(id);
        getline(cin, year);
        yearm[year].insert(id);
    }

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        string temp;
        scanf("%d: ", &n);
        getline(cin, temp);
        cout << n << ": " << temp << endl;
        if (n == 1) print(namem, temp);
        else if (n == 2) print(authorm, temp);
        else if (n == 3) print(keywordm, temp);
        else if (n == 4) print(publisherm, temp);
        else if (n == 5) print(yearm, temp);
    }
    return 0;
}