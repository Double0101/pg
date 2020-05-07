#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<int, string> no2na;
map<string, int> na2no;
int **G;

int maxno = 0;
int maxt = 0;
int total = 0;
bool isgang = false;
char num[1000] = {0};

int in = 0;
bool **visited;

void totaltime(int a, int c)
{
    if (visited[a][a])
        return;
    int tt = 0;
    for (int i = 0; i < c; ++i) {
        tt += G[i][a];
        tt += G[a][i];
    }
    if (tt > maxt) {
        maxt = tt;
        maxno = a;
    }
}

void find(int ina, int inb, int count, int thre)
{
    totaltime(ina, count);
    totaltime(inb, count);
    if (visited[ina][inb]) {
        return;
    }
    visited[ina][inb] = true;
    num[ina] = num[inb] = 1;
    total += G[ina][inb];
    if (total > thre) isgang = true;
    for (int i = 0; i < count; ++i) {
        if (G[ina][i]) {
            find(ina, i, count, thre);
            find(i, ina, count, thre);
        }
    }
    for (int j = 0; j < count; ++j) {
        if (G[j][inb]) {
            find(j, inb, count, thre);
            find(inb, j, count, thre);
        }
    }
}

int check(int count)
{
    int a = 0;
    for (int i = 0; i < count; ++i) {
        a += num[i];
    }
    return a;
}

int main()
{
    int threthold, count;
    cin >> count >> threthold;
    G = (int**) malloc(sizeof(int*) * count);
    visited = (bool**) malloc(sizeof(bool*) * count);
    for (int j = 0; j < count; ++j) {
        G[j] = (int*) malloc(sizeof(int) * count);
        memset(G[j], 0, sizeof(int) * count);
        visited[j] = (bool*) malloc(sizeof(bool) * count);
        memset(visited[j], 0, sizeof(bool) * count);
    }
    for (int i = 0; i < count; ++i) {
        string a1, a2;
        int minute;
        cin >> a1 >> a2 >> minute;
        if (na2no.find(a1) == na2no.end()) {
            int an = in++;
            na2no[a1] = an;
            no2na[an] = a1;
        }
        if (na2no.find(a2) == na2no.end()) {
            int an = in++;
            na2no[a2] = an;
            no2na[an] = a2;
        }
        G[na2no[a1]][na2no[a2]] = minute;
    }
    for (int l = 0; l < count; ++l) {
        maxno = 0;
        maxt = 0;
        memset(num, 0, 1000);
        total = 0;
        isgang = false;
        find(l, l, count, threthold);
        int n = check(count);
        if (isgang && n > 2) {
            cout << no2na[maxno] << " " << n << endl;
        }
    }
    return 0;
}
/*
 *
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
 * */