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
int snum;

int main()
{
    scanf("%lf %lf %lf %d", &capacity, &dest, &unitdis, &snum);
    vector<Station> way(snum+1);
    for (int i = 0; i < snum; ++i) {
        Station s;
        scanf("%lf %lf", &(s.gasprice), &(s.distance));
        way.push_back(s);
    }
    way.push_back({dest, 0.0});
    sort(way.begin(), way.end(), cmp);
    double nowdis = 0;
    double maxdis = capacity*unitdis;
    double nowprice;
    if (way[0].distance != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    } else {
        nowprice = way[0].gasprice;
    }
    while (nowdis < dest) {

    }

    return 0;
}