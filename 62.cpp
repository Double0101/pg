#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct man {
    int t;
    int id, vg, tg, total;
} M;

int N, L, H;

bool cmp(M m1, M m2)
{
    if (m1.t == m2.t) {
        if (m1.total == m2.total) {
            if (m1.vg == m2.vg)
                return m1.id < m2.id;
            return m1.vg > m2.vg;
        }
        return m1.total > m2.total;
    }
    return m1.t > m2.t;
}

int type(int v, int t) {
    if (v < L || t < L) return 0;
    if (v >= H && t >= H) return 4;
    if (t > v) return 1;
    if (v < H && t < H) return 2;
    return 3;
}

int main()
{
    scanf("%d%d%d", &N, &L, &H);
    vector<M> ms(N);
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ms[i].id = a;
        ms[i].vg = b;
        ms[i].tg = c;
        ms[i].total = b+c;
        ms[i].t = type(b, c);
    }
    sort(ms.begin(), ms.end(), cmp);
    int nn = 0;
    for (int i = 0; i < N; ++i) {
        if (ms[i].t > 0) ++nn;
    }
    printf("%d\n", nn);
    for (int i = 0; i < nn; ++i) {
        printf("%08d %d %d\n", ms[i].id, ms[i].vg, ms[i].tg);
    }
    return 0;
}