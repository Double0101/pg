#include <stdio.h>
#include <string.h>

int indigits[10] = {0};
int outdigits[10] = {0};

char innum[25] = {0};
char outnum[25] = {0};

int main()
{
    scanf("%s", innum);
    int inlen = strlen(innum);
    int tail = inlen;
    if (innum[0] < '5') --tail;
    outnum[tail+1] = '\0';
    char adv = 0;
    for (int i = inlen-1; i >= 0; --i) {
        char a = innum[i]-'0';
        ++indigits[a];
        a *= 2;
        a += adv;
        adv = a/10;
        a = a%10;
        ++outdigits[a];
        outnum[tail--] = '0'+a;
    }
    if (adv != 0) {
        outnum[tail] = '0'+adv;
    }

    int y = 0;
    for (int j = 0; j < 10; ++j) {
        if (outdigits[j] != indigits[j]) {
            y = 1;
            break;
        }
    }

    if (y == 1) {
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    printf("%s\n", outnum);

    return 0;
}
