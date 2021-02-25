#include <cstdio>
#include <cstring>

char str[100000];
char cp[100000];
int N;

int main()
{
    scanf("%s %d", cp, &N);
    int i = 1;
    while (i < N) {
        strcpy(str, cp);
        int len = strlen(str);
        char pre = str[0];
        int num = 1;
        int start = 0;
        for (int j = 1; j <= len; ++j) {
            if (str[j] == pre) ++num;
            else {
                cp[start++] = pre;
                cp[start++] = num+'0';
                pre = str[j];
                num = 1;
            }
        }
        cp[start] = '\0';
        ++i;
    }
    printf("%s\n", cp);
    return 0;
}
