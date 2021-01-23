#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct customer{
    int arrtime, sertime, waittime, playtime;
    bool vip, served;
} customer;

typedef struct table{
    int endtime;
    int vip;
    int cc;
    int index;
} table;

int N, K, M;
customer cus[10000];
table tab[101];
queue<int> q[2];

inline
int getTime(int h, int m, int s)
{
    return h*60*60 + m*60 + s;
}

bool cmp(customer c1, customer c2)
{
    return c1.arrtime < c2.arrtime;
}

bool cmpc(customer c1, customer c2)
{
    return c1.sertime < c2.sertime;
}

bool cmpt(table t1, table t2)
{
    return t1.endtime < t2.endtime;
}

bool cmpti(table t1, table t2)
{
    return t1.index < t2.index;
}
void qclear()
{
    for (int i = 0; i < 2; ++i) {
        if (!q[i].empty()) {
            while (cus[q[i].front()].served) q[i].pop();
        }
    }
}

void ptime(int time)
{
    int h = time/3600;
    int m = (time%3600)/60;
    int s = time%60;
    printf("%02d:%02d:%02d", h, m, s);
}

void print(int i)
{
    customer *c = cus+i;
    ptime(c->arrtime);
    printf(" ");
    ptime(c->sertime);
    printf(" %d\n", c->waittime);
}

int main()
{
    int vn = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int a, b, c, d, e;
        scanf("%d:%d:%d %d %d", &a, &b, &c, &d, &e);
        cus[i].arrtime = getTime(a, b, c);
        cus[i].playtime = d*60;
        vn += e;
        cus[i].vip = (e == 1);
        cus[i].served = false;
    }
    scanf("%d%d", &K, &M);
    int start = getTime(8, 0, 0);
    int end = getTime(21, 0, 0);
    for (int i = 0; i < K; ++i) {
        tab[i].endtime = start;
        tab[i].index = i;
        tab[i].vip = 0;
        tab[i].cc = 0;
    }
    for (int i = 0; i < M; ++i) {
        int a;
        scanf("%d", &a);
        tab[a-1].vip = 1;
    }
    sort(cus, cus+N, cmp);
    for (int i = 0; i < N; ++i) {
        if (cus[i].vip == 1) q[1].push(i);
        q[0].push(i);
    }
    for (int i = 0; i < N; ++i) {
        int index;
        qclear();
        sort(tab, tab+K, cmpt);
        if (tab[0].vip == 1 && (!q[1].empty())
            && tab[0].endtime >= cus[q[1].front()].arrtime) {
            index = q[1].front();
        } else {
            index = q[0].front();
        }
        if (tab[0].endtime >= end) break;
        cus[index].served = true;
        cus[index].sertime = max(cus[index].arrtime, tab[0].endtime);
        cus[index].waittime = (cus[index].sertime-cus[index].arrtime+59)/60;
        tab[0].endtime = cus[index].sertime + cus[index].playtime;
        ++(tab[0].cc);
    }
    sort(cus, cus+N, cmpc);
    for (int i = 0; i < N; ++i) {
        if (cus[i].served) print(i);
    }
    sort(tab, tab+K, cmpti);
    printf("%d", tab[0].cc);
    for (int i = 1; i < K; ++i) {
        printf(" %d", tab[i].cc);
    }
    printf("\n");
    return 0;
}
