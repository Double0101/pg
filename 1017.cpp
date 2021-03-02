#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Customer {
    int HH, MM, SS, arrtime, starttime, endtime, sertime;
} cus;
bool cmp(cus c1, cus c2) {
    return c1.arrtime < c2.arrtime;
}
int N, K;
vector<cus> cuss;
int winend[100];
int main()
{
    scanf("%d%d", &N, &K);
    cuss.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d:%d:%d %d", &(cuss[i].HH), &(cuss[i].MM),
              &(cuss[i].SS), &(cuss[i].sertime));
        cuss[i].arrtime = cuss[i].HH*3600+cuss[i].MM*60+cuss[i].SS;
        cuss[i].sertime *= 60;
    }
    sort(cuss.begin(), cuss.end(), cmp);
    fill(winend, winend+K, 8*3600);
    for (int i = 0; i < N; ++i) {
        if (i < K) {
            cuss[i].starttime = max(winend[i], cuss[i].arrtime);
            winend[i] = cuss[i].starttime + min(cuss[i].sertime, 3600);
            cuss[i].endtime = winend[i];
        } else {
            int win = 0, mint = winend[win];
            for (int j = 1; j < K; ++j) {
                if (winend[j] < mint) {
                    win = j;
                    mint = winend[j];
                }
            }
            cuss[i].starttime = max(mint, cuss[i].arrtime);
            winend[win] = cuss[i].starttime + min(cuss[i].sertime, 3600);
            cuss[i].endtime = winend[win];
        }
    }
    int cn = 0, wait = 0;
    for (int i = 0; i < N; ++i) {
        if (cuss[i].arrtime > 17*3600) continue;
        ++cn;
        wait += (cuss[i].starttime-cuss[i].arrtime);
    }
    printf("%.1lf\n", wait*1.0/cn/60);
    return 0;
}



















