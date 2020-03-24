#include <stdio.h>
#include <stdlib.h>

#define MAXL 1000

typedef long long LL;

int main()
{
    LL acc = 0;
    int a = 0;
    int pc[MAXL] = {0};
    char *p;
    int *cp;
    char s[MAXL];
    gets(s);

    for (p = s, cp = pc; *p != '\0'; ++p, ++cp) {
        *cp = a;
        if (*p == 'P') ++a;
    }

    a = 0;
    for (--p, --cp; p != s; --p, --cp) {
        if (*p == 'T') ++a;
        if (*p == 'A') {
            acc += ((*cp) * a);
        }
    }

    printf("%d\n", acc);

    return 0;
}