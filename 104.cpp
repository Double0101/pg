#include <cstdio>
typedef long long LL;
int N;
LL sum = 0;

int main()
{
    scanf("%d", &N);
    double ff;
    for (int i = 1; i <= N; ++i) {
        scanf("%lf", &ff);
        sum += (LL)(ff*1000)*i*(N+1-i);
    }
    printf("%.2f\n", sum/1000.0);
    return 0;
}