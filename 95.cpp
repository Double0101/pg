#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef struct Item {
    string plate;
    int time, ioo;
} item;
bool cmp1(item i1, item i2) { return i1.time < i2.time; }
bool cmp2(item i1, item i2) {
    if (i1.plate == i2.plate) return i1.time < i2.time;
    return i1.plate < i2.plate;
}
map<string, int> ptimes;
vector<item> records, parking;
int N, Q;
int time2i(int h, int m, int s) {
    return h*3600+m*60+s;
}
int main()
{
    scanf("%d%d", &N, &Q);
    records.resize(N);
    char p[10], io[10];
    int h, m, s;
    string ps;
    for (int i = 0; i < N; ++i) {
        scanf("%s %d:%d:%d %s", p, &h, &m, &s, io);
        records[i].plate = p;
        records[i].time = time2i(h, m, s);
        records[i].ioo = strcmp(io, "in") == 0 ? 1 : -1;
    }
    sort(records.begin(), records.end(), cmp2);
    int maxt = 0;
    for (int i = 1; i < N; ++i) {
        if (records[i].plate == records[i-1].plate
            && records[i].ioo == -1 && records[i-1].ioo == 1) {
            parking.push_back(records[i-1]);
            parking.push_back(records[i]);
            ptimes[records[i].plate] += (records[i].time-records[i-1].time);
            if (ptimes[records[i].plate] > maxt) maxt = ptimes[records[i].plate];
            ++i;
        }
    }
    sort(parking.begin(), parking.end(), cmp1);
    vector<int> carn(parking.size());
    for (int i = 0; i < parking.size(); ++i) {
        if (i == 0) carn[i] = parking[i].ioo;
        else carn[i] = carn[i-1] + parking[i].ioo;
    }
    int tindex = 0;
    for (int i = 0; i < Q; ++i) {
        scanf("%d:%d:%d", &h, &m, &s);
        int t = time2i(h, m, s);
        int j;
        for (j = tindex; j < parking.size() && parking[j].time <= t; ++j) tindex = j;
        printf("%d\n", carn[tindex]);
    }
    for (auto it : ptimes) {
        if (it.second == maxt) printf("%s ", it.first.c_str());
    }
    printf("%02d:%02d:%02d\n", maxt/3600, (maxt-maxt/3600*3600)/60, maxt%60);
    return 0;
}