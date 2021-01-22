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

    map<string, set<int>> *mp[5];
    mp[0] = &namem;
    mp[1] = &authorm;
    mp[2] = &keywordm;
    mp[3] = &publisherm;
    mp[4] = &yearm;
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        string temp;
        scanf("%d: ", &n);
        getline(cin, temp);
        cout << n << ": " << temp << endl;
        if ((*(mp[n-1])).find(temp) != (*(mp[n-1])).end()) {
            for (int i : (*mp[n-1])[temp]) {
                printf("%07d\n", i);
            }
        } else {
            printf("Not Found\n");
        }
    }


    return 0;
}