#include <cstdio>
#include <algorithm>

using namespace std;

int prime[40000];
int table[20000];
int Ms, rMs, N, M;

void htinit()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= 200; ++i) {
        if (prime[i] == 1) continue;
        for (int j = i*i; j < 40000; j+=i) {
            prime[j] = 1;
        }
    }
}

int main()
{
    htinit();
    scanf("%d%d%d", &Ms, &N, &M);
    rMs = Ms;
    while (prime[rMs] == 1) ++rMs;
    fill(table, table+rMs, -1);
    int flag;
    int a;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        flag = 0;
        for (int j = 0; j < rMs; ++j) {
            int index = (a+j*j)%rMs;
            if (table[index] == -1) {
                table[index] = a;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d cannot be inserted.\n", a);
        }
    }
    int fn = 0;
    for (int i = 0; i < M; ++i) {
        flag = 0;
        scanf("%d", &a);
        for (int j = 0; j <= rMs && flag == 0; ++j) {
            int index = (a+j*j)%rMs;
            ++fn;
            if (table[index] == a || table[index] == -1) {
                flag = 1;
            }
        }
    }
    printf("%.1lf\n", fn*1.0/M);
    return 0;
}
