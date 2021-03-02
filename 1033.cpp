#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct GasStation {
    double distance;
    double price;
} gs;
const double inf = 999999999;
bool cmp(gs g1, gs g2) { return g1.distance < g2.distance; }
double capacity, dst, avg;
int gn;
vector<gs> gss;
int main()
{
    scanf("%lf%lf%lf%d", &capacity, &dst, &avg, &gn);
    gss.resize(gn+1);
    for (int i = 0; i < gn; ++i) {
        scanf("%lf%lf", &(gss[i].price), &(gss[i].distance));
    }
    gss[gn].price = 0, gss[gn].distance = dst;
    sort(gss.begin(), gss.end(), cmp);
    double maxdis = capacity*avg;
    double gas = 0, pos = 0, price = 0;
    for (int i = 0; i <= gn && gss[i].distance < dst; ++i) {
        if (pos > gss[i].distance) continue;
        if (pos < gss[i].distance) {
            printf("The maximum travel distance = %.2lf\n", pos);
            return 0;
        }
        double minprice = inf;
        int g, ming = -1, flag = 0;
        for (g = i+1; g <= gn && gss[g].distance <= pos+maxdis; ++g) {
            if (gss[g].price <= gss[i].price) {
                flag = 1;
                break;
            }
            if (gss[g].price < minprice) {
                minprice = gss[g].price;
                ming = g;
            }
        }
        if (flag == 1) {
            double needg = (gss[g].distance-gss[i].distance)/avg;
            if (needg > gas) {
                price += (needg-gas)*gss[i].price;
                gas = 0;
            } else {
                gas -= needg;
            }
            pos = gss[g].distance;
        } else {
            price += (capacity-gas)*gss[i].price;
            if (ming != -1) {
                double needg = (gss[ming].distance-gss[i].distance)/avg;
                gas = capacity-needg;
                pos = gss[ming].distance;
            } else {
                pos += maxdis;
            }
        }
    }
    if (pos == dst) printf("%.2lf\n", price);
    else printf("The maximum travel distance = %.2lf\n", pos);
    return 0;
}