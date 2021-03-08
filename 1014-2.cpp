#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef struct Customer {
    int starttime, endtime, sertime;
} cus;

int N, M, K, Q;
vector<cus> cuss;
queue<int> win[20];
int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    cuss.resize(K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &(cuss[i].sertime));
    }
    for (int i = 0; i < M*N && i < K; ++i) {
        win[i%N].push(i);
    }
    for (int i = 0; i < N && i < K; ++i) {
        cuss[i].starttime = 8*60;
        cuss[i].endtime = cuss[i].starttime+cuss[i].sertime;
    }
    for (int i = M*N; i < K; ++i) {
        int w = 0, early = cuss[win[0].front()].endtime;
        for (int j = 1; j < N; ++j) {
            if (cuss[win[j].front()].endtime < early) {
                early = cuss[win[j].front()].endtime;
                w = j;
            }
        }
        win[w].push(i);
        int t = win[w].front(), next;
        win[w].pop();
        next = win[w].front();
        cuss[next].starttime = cuss[t].endtime;
        cuss[next].endtime = cuss[next].starttime + cuss[next].sertime;
    }
    for (int i = 0; i < N; ++i) {
        if (!win[i].empty()) {
            int t = win[i].front();
            win[i].pop();
            while (!win[i].empty()) {
                cuss[win[i].front()].starttime = cuss[t].endtime;
                t = win[i].front();
                cuss[t].endtime = cuss[t].starttime + cuss[t].sertime;
                win[i].pop();
            }
        }
    }
    int a;
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &a);
        --a;
        if (cuss[a].starttime >= 17*60) printf("Sorry\n");
        else {
            printf("%02d:%02d\n", cuss[a].endtime/60, cuss[a].endtime%60);
        }
    }
    return 0;
}
