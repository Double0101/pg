#include <iostream>
#include <map>
#include <string>

using namespace std;

int in;
int cc = 0;

bool *visited;
int **G;
int num;
int threthold;
int *ptime;
map<string, int> gang;
map<string, int> na2no;
map<int, string> no2na;

int id(string name)
{
    if (na2no.find(name) == na2no.end()) {
        int index = in++;
        na2no[name] = index;
        no2na[index] = name;
        return index;
    }
    return na2no[name];
}

void dfs(int index, int &head, int &totaltime, int &totalnum)
{
    ++totalnum;
    visited[index] = true;
    if (ptime[index] > ptime[head]) {
        head = index;
    }
    for (size_t i = 0; i < in; ++i) {
        if (G[index][i] == 0) continue;
        
        totaltime += G[index][i];
        G[index][i] = G[i][index] = 0;
        if (!visited[i]) {
            dfs(i, head, totaltime, totalnum);
        }
    }
}

void trace()
{
    for (size_t i = 0; i < in; i++)
    {
        if (visited[i]) {
            continue;
        }
        int head = i, totaltime = 0, totalnum = 0;
        dfs(i, head, totaltime, totalnum);
        if (totalnum > 2 && totaltime > threthold) {
            gang[no2na[head]] = totalnum;
        }
    }

}

int main()
{
    cin >> num >> threthold;
    G = (int**) malloc(sizeof(int*) * 2 * num);
    ptime = (int*) malloc(sizeof(int) * 2 * num);
    visited = (bool*) malloc(sizeof(bool) * 2 * num);
    for (size_t i = 0; i < 2 * num; ++i) {
        G[i] = (int*) malloc(sizeof(int) * 2 * num);
        for (size_t j = 0; j < 2 * num; ++j) {
            G[i][j] = 0;
        }
        ptime[i] = 0;
        visited[i] = false;
    }
    
    for (size_t i = 0; i < num; i++) {
        string n1, n2;
        int tt;
        cin >> n1 >> n2 >> tt;
        int id1 = id(n1);
        int id2 = id(n2);
        G[id1][id2] += tt;
        G[id2][id1] += tt;
        ptime[id1] += tt;
        ptime[id2] += tt;
    }
    trace();
    cout << gang.size() << endl;
    for (map<string, int>::iterator it = gang.begin(); it != gang.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}