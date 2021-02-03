#include <cstdio>

int num;

int main()
{
    scanf("%d", &num);
    int i = 1, total = 0;
    while (i <= num) {
        int left = num/(i*10);
        int a = num-left*i*10;
        int right = a%i;
        int now = a/i;
        if (now == 0) {
            total += (left*i);
        } else if (now == 1) {
            total += (left*i + right + 1);
        } else {
            total += ((left+1)*i);
        }
        i *= 10;
    }
    printf("%d\n", total);
    return 0;
}