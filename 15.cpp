#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#define ONLINE 1
#define OFFLINE 0

using namespace std;

typedef struct callItem {
    string name;
    int MM, dd, HH, mm;
    int line, time;
} callitem;

callitem callist[1000];

bool cmp(callitem c1, callitem c2) {
    return c1.name == c2.name ? c1.time < c2.time : c1.name < c2.name;
}

int tolls[25] = {0};
int N;

double paybill(callitem item) {
    double bill;
    bill = tolls[24]*60*item.dd + tolls[item.HH]*item.mm;
    for (int i = 0; i < item.HH; ++i) {
        bill += tolls[i] * 60;
    }
    return bill/100.0;
}

int main()
{
    for (int i = 0; i < 24; ++i) {
        scanf("%d", tolls+i);
        tolls[24] += tolls[i];
    }
    scanf("%d", &N);
    string ll;
    for (int i = 0; i < N; ++i) {
        cin >> callist[i].name;
        scanf("%d:%d:%d:%d",
              &(callist[i].MM), &(callist[i].dd),
              &(callist[i].HH), &(callist[i].mm));
        cin >> ll;
        if (ll == "on-line")
            callist[i].line = ONLINE;
        else
            callist[i].line = OFFLINE;
        callist[i].time = callist[i].dd * 24 * 60 + callist[i].HH * 60 + callist[i].mm;
    }

    sort(callist, callist+N, cmp);

    map<string, vector<callitem>> custom;
    for (int i = 1; i < N; ++i) {
        if (callist[i].name == callist[i-1].name
            && callist[i-1].line == ONLINE
            && callist[i].line == OFFLINE) {
            custom[callist[i].name].push_back(callist[i-1]);
            custom[callist[i].name].push_back(callist[i]);
        }
    }
    for (auto it : custom) {
        vector<callitem> vec = it.second;
        cout << it.first;
        printf(" %02d\n", vec[0].MM);
        double total = 0.0;
        for (int i = 1; i < vec.size(); i += 2) {
            double b = paybill(vec[i]) - paybill(vec[i-1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                   vec[i-1].dd, vec[i-1].HH, vec[i-1].mm,
                   vec[i].dd, vec[i].HH, vec[i].mm, vec[i].time-vec[i-1].time, b);
            total += b;
        }
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}