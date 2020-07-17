#include <cstdio>
#include <vector>

using namespace std;

typedef struct supplier {
    int snum;
    vector<int> downs;
} Sup;

Sup sups[100010];

int num;
double price;
double rate;

void postt(int index, double &total, double price, double r)
{
    Sup s = sups[index];
    for (int i = 0; i < s.downs.size(); ++i) {
        postt(s.downs[i], total, price*r, r);
    }
    if (s.downs.size() == 0) {
        total += (s.snum*price);
    }
}

int main()
{
    scanf("%d %lf %lf", &num, &price, &rate);
    rate = 1 + (rate/100);
    for (int i = 0; i < num; ++i) {
        int c;
        scanf("%d", &c);
        for (int j = 0; j < c; ++j) {
            int n;
            scanf("%d", &n);
            sups[i].downs.push_back(n);
        }
        if (c == 0) {
            scanf("%d", &(sups[i].snum));
        }
    }
    double tp = 0;
    postt(0, tp, price, rate);
    printf("%.1lf\n", tp);

    return 0;
}