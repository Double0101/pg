#include <stdio.h>
#include <string.h>


int huiwen()
{
    char ss[256];
    gets(ss);

    int len = strlen(ss);

    int i = len >> 1, j = 0;

    while (j < i) {
        if (ss[j] != ss[len -j - 1]) {
            printf("%s\n", "NO");
            return 0;
        }
        ++j;
    }
    printf("%s\n", "YES");
    return 0;
}
