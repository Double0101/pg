#include <stdio.h>

int flist[110];

int num, total = 0;

int main()
{
    scanf("%d", &num);
    flist[0] = 0;
    for (int i = 1; i <= num; ++i) {
        scanf("%d", flist+i);
    }
    int up = 0, down = 0;
    for (int j = 1; j <= num; ++j) {
        int ud = flist[j] - flist[j-1];
        if (ud > 0) up += ud;
        else if (ud < 0) down -= ud;
    }
    total = (up*6) + (down*4) + (num*5);
    printf("%d\n", total);

    return 0;
}