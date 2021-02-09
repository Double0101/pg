#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct mooncake {
    double storage, profit, perpro;
} MC;

bool cmp(MC m1, MC m2)
{
    return m1.perpro > m2.perpro;
}

int main()
{
    int N;
    double D;
    scanf("%d%lf", &N, &D);
    vector<MC> ms(N);
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &(ms[i].storage));
    }
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &(ms[i].profit));
        ms[i].perpro = ms[i].profit/ms[i].storage;
    }
    sort(ms.begin(), ms.end(), cmp);
    double d = 0, profits = 0;
    for (int i = 0; i < N; ++i) {
        if (d+ms[i].storage < D) {
            d += ms[i].storage;
            profits += ms[i].profit;
            continue;
        }
        if (d+ms[i].storage >= D) {
            profits += ((D-d)*ms[i].perpro);
            d = D;
            break;
        }
    }
    printf("%.02lf\n", profits);
    return 0;
}