#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct station {
    double distance;
    double gasprice;
} Station;

bool cmp(Station s1, Station s2)
{
    return s1.distance < s2.distance;
}

double capacity, dest, unitdis;
double inf = 99999999;
int snum;

int main()
{
    scanf("%lf %lf %lf %d", &capacity, &dest, &unitdis, &snum);
    vector<Station> way;
    for (int i = 0; i < snum; ++i) {
        Station s;
        scanf("%lf %lf", &(s.gasprice), &(s.distance));
        way.push_back(s);
    }
    way.push_back({dest, 0.0});
    sort(way.begin(), way.end(), cmp);
    double nowdis = 0;
    double leftdis = 0;  //  leftdis是油箱里剩余的油还能行驶的距离
    double nowprice, totalprice = 0;
    if (way[0].distance != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    } else {
        nowprice = way[0].gasprice;
    }
    double maxlen = capacity*unitdis;
    while (nowdis < dest) {
        int maxdis = nowdis + maxlen;
        double lowprice = inf;
        int lowstation = -1;
        int flag = 0;
        for (int i = 1; i <= snum && way[i].distance <= maxdis; ++i) {
            if (way[i].distance <= nowdis) continue;
            /* 去能到达的范围内的第一个价格不高于现价的加油站 */
            if (way[i].gasprice <= nowprice) {
                if (way[i].distance-nowdis-leftdis >= 0) {
                    totalprice += (way[i].distance-nowdis-leftdis)*nowprice/unitdis;
                    leftdis = 0;
                } else {
                    leftdis -= (way[i].distance-nowdis);
                }
                nowdis = way[i].distance;
                nowprice = way[i].gasprice;
                flag = 1;
                break;
            }
            if (way[i].gasprice < lowprice) {
                lowprice = way[i].gasprice;
                lowstation = i;
            }
        }
        if (flag == 0 && lowstation == -1) {
            printf("The maximum travel distance = %.2f\n", maxdis);
            return 0;
        }
        if (flag) continue;
        totalprice += (maxdis-leftdis)*nowprice/unitdis;
        leftdis = maxdis - way[lowstation].distance;
        nowdis = way[lowstation].distance;
        nowprice = way[lowstation].gasprice;
    }

    printf("%.2f\n", totalprice);

    return 0;
}