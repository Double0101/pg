#include <cstdio>
#include <cstring>

char num1[110], num2[110];
char nf1[110], nf2[110];
int n, d1, d2;

void standard(char *src, int bn, char *dst) {
    char *fp = src;
    char *dp = dst;
    *(dp++) = '0';
    *(dp++) = '.';
    while (*fp == '0' || *fp == '.') ++fp;
    char *fpf = fp;
    for (int i = 0; i < bn; ++i) {
        if (*fpf == '\0') {
            *(dp++) = '0';
            continue;
        }
        if (*fpf == '.') ++fpf;
        *(dp++) = *(fpf++);
    }
    *(dp++) = '*';
    *(dp++) = '1';
    *(dp++) = '0';
    *(dp++) = '^';
    char *fpp = src;
    while (*fpp != '.' && *fpp != '\0') ++fpp;
    int k = fpp-fp;
    if (*fp == '\0') k = 0;
    if (k < 0) {
        ++k;
        *(dp++) = '-';
        k = 0-k;
    }
    int a = 100;
    while (a > k) a /= 10;
    if (a == 0) *(dp++) = '0';
    while (a != 0) {
        int i = k/a;
        *(dp++) = '0' + i;
        k -= (i*a);
        a /= 10;
    }
    *(dp++) = '\0';
}

int main()
{
    scanf("%d %s %s", &n, num1, num2);
    standard(num1, n, nf1);
    standard(num2, n, nf2);
    if (strcmp(nf1, nf2) != 0) {
        printf("NO %s %s\n", nf1, nf2);
    } else {
        printf("YES %s\n", nf1);
    }
    return 0;
}
