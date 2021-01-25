#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

double inf = 99999999;

typedef struct station {
    double gasprice, distance;
} Station;

bool cmp(Station s1, Station s2)
{
    return s1.distance < s2.distance;
}

int main()
{
    double capacity, dest, avgu;
    int snum;
    scanf("%lf %lf %lf %d", &capacity, &dest, &avgu, &snum);
    vector<Station> way(snum+1);
    way[0].gasprice = 0;
    way[0].distance = dest;
    for (int i = 1; i <= snum; ++i) {
        scanf("%lf %lf", &(way[i].gasprice), &(way[i].distance));
    }
    sort(way.begin(), way.end(), cmp);
    double nowdis = 0, leftdis = 0, maxlen = capacity*avgu, nowprice, totalprice = 0;
    if (way[0].distance != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    } else {
        nowprice = way[0].gasprice;
    }
    while (nowdis < dest) {
        double maxdis = nowdis + maxlen;
        int flag = 0, lwsta = -1;
        double lwprice = inf;
        for (int i = 1; i <= snum && way[i].distance <= maxdis; ++i) {
            if (way[i].distance <= nowdis) continue;
            if (way[i].gasprice <= nowprice) {
                if (way[i].distance - nowdis >= leftdis) {
                    totalprice += ((way[i].distance-nowdis-leftdis) * nowprice / avgu);
                    leftdis = 0;
                } else {
                    leftdis -= (way[i].distance-nowdis);
                }
                nowprice = way[i].gasprice;
                nowdis = way[i].distance;
                flag = 1;
                break;
            }
            if (way[i].gasprice < lwprice) {
                lwprice = way[i].gasprice;
                lwsta = i;
            }
        }
        if (flag == 1) continue;
        if (lwsta == -1) {
            printf("The maximum travel distance = %.2lf\n", maxdis);
            return 0;
        }
        totalprice += (maxlen-leftdis)*nowprice/avgu;
        leftdis = maxlen-way[lwsta].distance+nowdis;
        nowdis = way[lwsta].distance;
        nowprice = lwprice;
    }
    printf("%.2lf\n", totalprice);
    return 0;
}
