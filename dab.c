#include <stdio.h>


int dab()
{
    int i,j,k,m = 1;
    scanf("%d %d %d", &i, &j, &k);

    i += j;
    j = 0;

    while (i) {
        int x = i%k;
        j += m*x;
        m *= 10;
        i /= k;
    }

    printf("%d\n", j);
    return 0;
}
