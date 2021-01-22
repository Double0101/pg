#include <cstdio>

int bnum[10] = {0};
int bnum1[10] = {0};

char numb[25] = {0};
char numa[25];

int main()
{
    numa[0] = numb[0] = 0;
    scanf("%s", numa+1);
    int len = 1;
    while (numa[len] != '\0') {
        ++len;
    }
    for (int j = 1; j < len; ++j) {
        numa[j] = numa[j] - '0';
    }
    for (int j = len-1; j > 0; --j) {
        numb[j] += numa[j]*2;
        numb[j-1] += (numb[j]/10);
        numb[j] = (numb[j]%10);
        ++bnum[numa[j]];
        ++bnum1[numb[j]];
    }

    for (int i = 0; i < len; ++i) {
        numb[i] = numb[i]+'0';
    }
    int flag = 0;
    for (int i = 0; i < 10; ++i) {
        if (bnum[i] != bnum1[i]) {
            flag = 1;
            break;
        }
    }
    if (flag) printf("No\n");
    else printf("Yes\n");
    int i = numb[0] == '0' ? 1 : 0;
    for (; i < len; ++i) {
        printf("%c", numb[i]);
    }
    printf("\n");

    return 0;
}