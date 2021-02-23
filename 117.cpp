#include <cstdio>

int disN[100002] = {0};
int N;

int main()
{
    scanf("%d", &N);
    int dis;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &dis);
        if (dis > N) ++disN[N+1];
        else ++disN[dis];
    }
    int day = disN[N+1];
    int i;
    for (i = N; i >= 0; --i) {
        if (day >= i) break;
        day += disN[i];
    }
    printf("%d\n", i);
    return 0;
}
