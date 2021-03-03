#include <cstdio>
#include <cstring>

char input[10000];
char num[10000];
int exp;

int main()
{
    scanf("%s", input);
    int len = strlen(input);
    int i = 0;
    while (i < len && input[i] != 'E') ++i;
    input[i] = ' ';
    sscanf(input, "%s %d", num, &exp);
    num[2] = num[1];
    num[1] = num[0];
    char *nub = num+1;
    if (nub[0] == '-') printf("-");
    if (exp < 0) {
        for (int j = 0; j < -exp; ++j) {
            printf("0");
            if (j == 0) printf(".");
        }
        printf("%s\n", nub+1);
    } else {
        len = strlen(nub);
        for (int j = 1; j < len; ++j) {
            if (j == exp+2) printf(".");
            printf("%c", nub[j]);
        }
        if (exp+2 > len) {
            for (int j = 0; j < exp + 2 - len; ++j) {
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}
