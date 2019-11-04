#include <stdio.h>

int findx(int argc, char const *argv[])
{
    int maxn = 210;
    int array[maxn];
    int i = 0, n, count;
    scanf("%d", &count);
    while (i < count) {
        scanf("%d", &array[i++]);
    }

    scanf("%d", &n);
    i = 0;
    while (i < count) {
        if (array[i] == n)
        {
            printf("%d\n", i);
            return 0;
        }
        ++i;
    }

    printf("%d\n", -1);
    return 0;
}
