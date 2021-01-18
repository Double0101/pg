#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct customer{
    int arrtime, postime;
} customer;

typedef struct window{
    int end;
} window;

int time(int h, int m, int s) {
    return h*60*60+m*60+s;
}

bool cmp(customer c1, customer c2) {
    return c1.arrtime < c2.arrtime;
}

customer cus[10000];
window win[100];
int N, K;


int main()
{
    scanf("%d%d", &N, &K);
    int stt = time(8,0,0);
    int ent = time(17,0,0);
    for (int i = 0; i < N; ++i) {
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        cus[i].arrtime = time(h, m, s);
        cus[i].postime = p*60;
        if (p > 60) cus[i].postime = 3600;
    }
    for (int i = 0; i < K; ++i) {
        win[i].end = stt;
    }

    sort(cus, cus+N, cmp);

    double totalw = 0;
    int totals = 0;

    for (int i = 0; i < N; ++i) {
        if (cus[i].arrtime > ent) break;
        int w = 0;
        for (int j = 1; j < K; ++j)
            if (win[j].end < win[w].end) w = j;
        if (cus[i].arrtime > win[w].end) {
            win[w].end = cus[i].arrtime;
        }
        totalw += win[w].end - cus[i].arrtime;
        ++totals;
        win[w].end += cus[i].postime;
    }

    printf("%.1f\n", totalw/totals/60);

    return 0;
}
