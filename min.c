#include <stdio.h>
#include <stdlib.h>


int icmp(int *i1, int *i2) {
    return *i1 - *i2;
}

int main()
{
    int i, num[10];
    for (i = 0; i < 10; ++i) {
        scanf("%d", &num[i]);
    }
    qsort(num, 10, sizeof(int), icmp);
    i = 0;

    while (i < 10 && num[i] == 0) ++i;

    printf("%d", num[i]);
    for (int j = 0; j < 10; ++j) {
        if (j != i) {
            printf("%d", num[j]);
        }
    }
    return 0;
}
