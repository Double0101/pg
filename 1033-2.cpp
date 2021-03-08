#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct GasStation {
    double distance, price;
} GS;
bool cmp(GS g1, GS g2) {
    return g1.distance < g2.distance;
}
const double inf = 99999999999;
vector<GS> way;
double capacity, per, dst;
int N;
int main()
{
    scanf("%lf%lf%lf%d", &capacity, &dst, &per, &N);
    way.resize(N+1);
    way[0].distance = dst, way[0].price = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%lf%lf", &(way[i].price), &(way[i].distance));
    }
    sort(way.begin(), way.end(), cmp);
    double now = 0, gas = 0, maxdis = capacity*per, total = 0;
    for (int i = 0; i <= N && way[i].distance <= dst; ++i) {
        if (now < way[i].distance) {
            printf("The maximum travel distance = %.2lf\n", now);
            return 0;
        }
        int min = -1, flag = 0;
        double minprice = inf;
        for (int j = i+1; j <= N && way[j].distance <= now+maxdis; ++j) {
            if (way[j].price <= way[i].price) {
                flag = 1;
                min = j;
                break;
            }
            else if (way[j].price < minprice) {
                min = j;
                minprice = way[j].price;
            }
        }
        double need;
        if (min != -1) {
            need = (way[min].distance-now)/per;
            now = way[min].distance;
        }
        if (flag == 1) {
            if (need > gas) {
                total += (need-gas)*way[i].price;
                gas = 0;
            } else {
                gas -= need;
            }
        } else {
            if (min == -1) {
                now += maxdis;
            } else {
                total += (capacity-gas)*way[i].price;
                gas = capacity-need;
            }
        }
        if (now == dst) break;
    }
    printf("%.2lf\n", total);
    return 0;
}