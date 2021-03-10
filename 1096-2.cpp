#include <cstdio>
#include <cmath>

int main()
{
    int num;
    scanf("%d", &num);
    int end = sqrt(num);
    int start, tmpstart, max = -1, tmpm, tm;
    for (int i = 2; i <= end; ++i) {
        if (num%i != 0) continue;
        tmpstart = i;
        tm = num/i;
        int j;
        for (j = tmpstart+1; j <= end && tm%j == 0; ++j) {
            tm/=j;
        }
        tmpm = j-tmpstart;
        if (tmpm > max) {
            max = tmpm;
            start = tmpstart;
        }
    }
    if (max == -1) {
        max = 1;
        start = num;
    }
    printf("%d\n", max);
    for (int i = 0; i < max-1; ++i) {
        printf("%d*", start+i);
    }
    printf("%d\n", start+max-1);
    return 0;
}
