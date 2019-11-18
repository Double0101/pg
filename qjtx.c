#include <stdio.h>
#include <stdlib.h>


typedef struct inteval {
    int x;
    int y;
} inteval;

inteval I[100];

int inteval_cmp(inteval *i1, inteval *i2)
{
    if (i1->x != i2->x) return i2->x - i1->x;
    else return i1->y - i2->y;
}


int main()
{
    int n, i, count = 1, lastx;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d %d", &I[i].x, &I[i].y);
    }
    qsort(I, n, sizeof(inteval), inteval_cmp);

    i = 1;
    lastx = I[0].x;
    while (i < n) {
        if (I[i].y <= lastx) {
            lastx = I[i].x;
            ++count;
        }
        ++i;
    }

    printf("%d\n", count);
    return 0;
}
