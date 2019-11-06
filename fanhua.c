#include <stdio.h>
#include <string.h>


int fanhua()
{
    char str[81];
    char res[81];
    gets(str);
    int len = strlen(str), i=0, j=0;
    while (i <= len) {
        if (str[i] == ' ' || i == len) {
            int ll = len - i;
            while (j != i) {
                res[ll++] = str[j++];
            }
            res[ll] = ' ';
            ++j;
        }
        ++i;
    }
    res[len] = '\0';
    printf("%s\n", res);

    return 0;
}
