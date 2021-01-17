#include <cstdio>
#include <queue>

using namespace std;

struct customer {
    int sertime, start, end;
} customers[1000];

queue<int> cq[20];

int wc, yc, cc, qc;

int main()
{
    scanf("%d%d%d%d", &wc, &yc, &cc, &qc);
    for (int i = 0; i < cc; ++i) {
        scanf("%d", &customers[i].sertime);
    }

    for (int i = 0; i < cc; ++i) {
        if (i < wc*yc) {
            cq[i%wc].push(i);
            if (i < wc) {
                customers[i].start = 0;
                customers[i].end = customers[i].sertime;
            }
        } else {
            int earlyw = 0;
            int wintime = customers[cq[0].front()].end;
            for (int j = 1; j < wc; ++j) {
                if (customers[cq[j].front()].end < wintime) {
                    earlyw = j;
                    wintime = customers[cq[j].front()].end;
                }
            }
            int cu = cq[earlyw].front();
            cq[earlyw].pop();
            customers[cq[earlyw].front()].start = customers[cu].end;
            customers[cq[earlyw].front()].end =
                    customers[cq[earlyw].front()].start
                    + customers[cq[earlyw].front()].sertime;
            cq[earlyw].push(i);
        }
    }
    for (int i = 0; i < wc; ++i) {
        while (!cq[i].empty()) {
            int cus = cq[i].front();
            cq[i].pop();
            if (!cq[i].empty()) {
                int cus2 = cq[i].front();
                customers[cus2].start = customers[cus].end;
                customers[cus2].end = customers[cus2].start + customers[cus2].sertime;
            }
        }
    }

    customer *cp = customers-1;
    for (int i = 0; i < qc; ++i) {
        int cusid;
        scanf("%d", &cusid);
        customer ccc = cp[cusid];
        if ((ccc.start/60)+8 >= 17)
            printf("Sorry\n");
        else {
            printf("%02d:%02d\n", (ccc.end/60)+8, ccc.end%60);
        }
    }
    

    return 0;
}