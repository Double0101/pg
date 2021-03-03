#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
bool prime[30001];
int table[30001];
int N, Q, Msize, a;
void init() {
    fill(prime, prime+30001, true);
    prime[0] = prime[1] = false;
    int end = sqrt(30001);
    for (int i = 2; i <= end; ++i) {
        if (prime[i] == false) continue;
        for (int j = i*i; j <= 30001; j += i) {
            prime[j] = false;
        }
    }
}

int main()
{
    init();
    scanf("%d%d", &N, &Q);
    Msize = N;
    while (prime[Msize] == false) ++Msize;
    fill(table, table+Msize, -1);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &a);
        int flag = 0;
        for (int j = 0; j < Msize; ++j) {
            int index = (a+j*j)%Msize;
            if (table[index] == -1) {
                table[index] = a;
                if (i != 0) printf(" ");
                printf("%d", index);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            if (i != 0) printf(" ");
            printf("-");
        }
    }
    return 0;
}