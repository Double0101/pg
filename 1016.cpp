#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct Record {
    string name;
    int time, month, day, hour, minute, ioo;
} rec;
bool cmp(rec &r1, rec &r2) {
    return r1.name == r2.name ?
        r1.time < r2.time : r1.name < r2.name;
}
int price[25] = {0}, N;
vector<rec> recs;
double bill(rec &r) {
    double b = price[24]*60*r.day + price[r.hour]*r.minute;
    for (int i = 0; i < r.hour; ++i) {
        b += price[i]*60;
    }
    return b/100;
}
int main()
{
    for (int i = 0; i < 24; ++i) {
        scanf("%d", price+i);
        price[24] += price[i];
    }
    scanf("%d", &N);
    recs.resize(N);
    char line[20], name[20];
    for (int i = 0; i < N; ++i) {
        scanf("%s %d:%d:%d:%d %s",
              name, &(recs[i].month), &(recs[i].day),
              &(recs[i].hour), &(recs[i].minute), line);
        if (strcmp(line, "on-line") == 0) recs[i].ioo = 0;
        else recs[i].ioo = 1;
        recs[i].name = name;
        recs[i].time = recs[i].day*24*60+recs[i].hour*60+recs[i].minute;
    }
    sort(recs.begin(), recs.end(), cmp);
    vector<rec> valid;
    for (int i = 1; i < N; ++i) {
        if (recs[i].name == recs[i-1].name
            && recs[i].month == recs[i-1].month
            && recs[i].ioo == 1 && recs[i-1].ioo == 0) {
            valid.push_back(recs[i-1]);
            valid.push_back(recs[i++]);
        }
    }
    string pname = "";
    double total = 0;
    for (int i = 1; i < valid.size(); i += 2) {
        if (valid[i].name != pname) {
            if (i != 1) printf("Total amount: $%.2lf\n", total);
            total = 0;
            printf("%s %02d\n", valid[i].name.c_str(), valid[i].month);
        }
        double bl = bill(valid[i])-bill(valid[i-1]);
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
               valid[i-1].day, valid[i-1].hour, valid[i-1].minute,
               valid[i].day, valid[i].hour, valid[i].minute,
               valid[i].time-valid[i-1].time, bl);
        total += bl;
        pname = valid[i].name;
    }
    if (!valid.empty()) printf("Total amount: $%.2lf\n", total);
    return 0;
}
