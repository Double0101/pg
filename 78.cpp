#include <cstdio>
#include <algorithm>

using namespace std;

bool ptable[100005];
bool htable[100005];

void primetable() {
    fill(ptable, ptable+100005, true);
    ptable[0] = ptable[1] = false;
    for (int i = 2; i < 50003; ++i) {
        if (ptable[i] == false) continue;
        for (int j = i+i; j < 100005; j += i) {
            ptable[j] = false;
        }
    }
}

int main()
{
    primetable();
    fill(htable, htable+100005, false);
    int Msize, N, ss;
    scanf("%d%d", &Msize, &N);
    while (ptable[Msize] == false) ++Msize;
    ss = (Msize+1)/2;
    int a;
    scanf("%d", &a);
    printf("%d", a%Msize);
    htable[a%Msize] = true;
    for (int i = 1; i < N; ++i) {
        int flag = 0;
        scanf("%d", &a);
        for (int j = 0; j <= ss; ++j) {
            int ind = (a+j*j)%Msize;
            if (htable[ind] == false) {
                printf(" %d", ind);
                htable[ind] = true;
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf(" -");
    }
    printf("\n");
    return 0;
}