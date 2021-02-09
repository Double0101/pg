#include <cstdio>

int main()
{
    char tnum[20480];
    scanf("%s", tnum);
    tnum[2] = tnum[1];
    tnum[1] = tnum[0];
    char *snum = tnum+1;
    int i = 0, es = 1, ei = 0;
    while (snum[i] != 'E') ++i;
    snum[i++] = '\0';
    if (snum[i++] == '-') es = -1;
    while (snum[i] != '\0') {
        ei = ei * 10 + snum[i++] - '0';
    }
    ei *= es;
    if (snum[0] == '-') printf("-");
    if (ei < 0) {
        printf("0.");
        ei = 0-ei;
        for (int j = 1; j < ei; ++j) {
            printf("0");
        }
        printf("%s", snum+1);
    } else {
        int j;
        for (j = 1; snum[j] != '\0'; ++j) {
            if (j == ei+2) printf(".");
            printf("%c", snum[j]);
        }
        for (; j <= ei+1; ++j) {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}