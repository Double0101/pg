#include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    int i = 1, right, left, now, total = 0;
    while (i <= N) {
        right = N%i;
        left = N/(i*10);
        now = N%(i*10)/i;
        if (now == 0) {
            total += left*i;
        } else if (now == 1) {
            total += left*i + right+1;
        } else {
            total += (left+1)*i;
        }
        i *= 10;
    }
    printf("%d\n", total);
    return 0;
}