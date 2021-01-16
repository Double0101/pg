#include <cstdio>
#include <queue>

using namespace std;

struct line {
    int id;
    queue<int> q;
    int nextTime;
} qls[20];

int wc, yc, cc, qc;
int customers[1001] = {0};
int done[1001] = {0};

void printTime(int m)
{
    int mm = m % 60;
    int hh = (m / 60) + 8;
    if (hh > 17 || (hh == 17 && mm > 0)) printf("Sorry\n");
    else printf("%02d:%d\n", hh, mm);
}

int main()
{
    for (int i = 0; i < 10; ++i) {
        qls[i].id = i;
        qls[i].nextTime = 0;
    }
    scanf("%d%d%d%d", &wc, &yc, &cc, &qc);
    for (int i = 1; i <= cc; ++i) {
        scanf("%d", customers+i);
    }

    for (int i = 1; i <= cc; ++i) {

    }

    return 0;
}