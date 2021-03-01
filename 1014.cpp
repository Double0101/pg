#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef struct Customer{
    int starttime, endtime, sertime;
} cus;
int N, M, K, Q;
vector<cus> cuss;
queue<int> wins[20];

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    cuss.resize(K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &(cuss[i].sertime));
    }
    for (int i = 0; i < K; ++i) {
        if (i < M*N) {
            wins[i%N].push(i);
            if (i < N) {
                cuss[i].starttime = 8*60;
                cuss[i].endtime = cuss[i].starttime + cuss[i].sertime;
            }
        } else {
            int win = -1, mintime = 999999999;
            for (int j = 0; j < N; ++j) {
                if (cuss[wins[j].front()].endtime < mintime) {
                    win = j, mintime = cuss[wins[j].front()].endtime;
                }
            }
            int c = wins[win].front();
            wins[win].pop();
            wins[win].push(i);
            cuss[wins[win].front()].starttime = cuss[c].endtime;
            cuss[wins[win].front()].endtime = cuss[c].endtime + cuss[wins[win].front()].sertime;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!wins[i].empty()) {
            int c = wins[i].front();
            wins[i].pop();
            while (!wins[i].empty()) {
                int t = wins[i].front();
                wins[i].pop();
                cuss[t].starttime = cuss[c].endtime;
                cuss[t].endtime = cuss[t].starttime+cuss[t].sertime;
                c = t;
            }
        }
    }
    int c;
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &c);
        if (cuss[c-1].starttime < 17*60) {
            printf("%02d:%02d\n", cuss[c-1].endtime/60, cuss[c-1].endtime%60);
        } else {
            printf("Sorry\n");
        }
    }
    return 0;
}
