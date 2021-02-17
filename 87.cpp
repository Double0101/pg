#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int inf = 999999999;
const int MXN = 26*26*26+1;
int hah(string s) {
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        id = id*26+s[i]-'A';
    }
    return id;
}
int id[MXN];
int getindex(string s) {
    return id[hah(s)];
}
int N, R, dst, rcount = 0, maxh = -1;
vector<string> names;
vector<int> happiness;
vector<bool> visited;
vector<vector<int>> pre;
vector<int> dis;
vector<vector<pair<int, int>>> roads;
vector<int> path, tmppath;

void dfs(int city)
{
    tmppath.push_back(city);
    if (city == 0) {
        ++rcount;
        int m = 0;
        for (int i : tmppath) {
            m += happiness[i];
        }
        if (m > maxh) {
            maxh = m;
            path = tmppath;
        }
    }
    for (int p : pre[city]) dfs(p);
    tmppath.pop_back();
}

int main()
{
    cin >> N >> R;
    names.resize(N);
    happiness.resize(N);
    visited.resize(N, false);
    pre.resize(N);
    dis.resize(N, inf);
    roads.resize(N);
    cin >> names[0];
    happiness[0] = 0;
    id[hah(names[0])] = 0;
    for (int i = 1; i < N; ++i) {
        cin >> names[i] >> happiness[i];
        id[hah(names[i])] = i;
    }
    string c1, c2;
    int cost, c1i, c2i;
    for (int i = 0; i < R; ++i) {
        cin >> c1 >> c2 >> cost;
        c1i = getindex(c1);
        c2i = getindex(c2);
        roads[c1i].push_back(make_pair(c2i, cost));
        roads[c2i].push_back(make_pair(c1i, cost));
    }
    dst = getindex("ROM");
    dis[0] = 0;
    for (int i = 0; i < N; ++i) {
        int vc = -1, minr = inf;
        for (int j = 0; j < N; ++j) {
            if (visited[j] == false && dis[j] < minr) {
                vc = j;
                minr = dis[j];
            }
        }
        if (vc == -1) break;
        visited[vc] = true;
        if (vc == dst) break;
        for (auto it : roads[vc]) {
            if (visited[it.first]) continue;
            if (dis[it.first] > dis[vc]+it.second) {
                dis[it.first] = dis[vc]+it.second;
                pre[it.first].clear();
            }
            if (dis[it.first] == dis[vc]+it.second) {
                pre[it.first].push_back(vc);
            }
        }
    }
    dfs(dst);
    printf("%d %d %d %d\n", rcount, dis[dst], maxh, maxh/(path.size()-1));
    cout << names[path[path.size()-1]];
    for (int i = path.size()-2; i >= 0; --i) {
        cout << "->" << names[path[i]];
    }
    cout << endl;
    return 0;
}
