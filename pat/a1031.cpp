#include <cstdio>
#include <cstring>

char sss[81];
char sps[28];
int sl;

int main()
{
    scanf("%s", sss);
    sl = strlen(sss);
    int el = (sl+2) / 3;
    int bl = sl - 2*el;
    int i;
    for (i = 0; i < bl; ++i) {
        sps[i] = ' ';
    }
    sps[i] = '\0';
    char *h = sss, *t = sss+sl-1;
    for (int j = 0; j < el-1; ++j) {
        printf("%c%s%c\n", *h, sps, *t);
        ++h, --t;
    }
    for (; h != t; ++h) {
        printf("%c", *h);
    }
    printf("%c\n", *t);
    return 0;
}