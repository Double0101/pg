#include <cstdio>
#include <cstring>

char bunit[3][5] = {"", " Wan", " Yi"};
char sunit[4][6] = {"", " Shi", " Bai", " Qian"};
char digit[10][5] = {"ling", "yi", "er", "san", "si",
                     "wu", "liu", "qi", "ba", "jiu"};

char number[15];

int main() {
    scanf("%s", number);
    char *num = number;
    if (num[0] == '-') {
        printf("Fu ");
        num += 1;
    }
    int len = strlen(num);
    int start, end, pzero = 0;
    for (start = 0, end = len-len/4*4; start < len; start = end, end += 4) {
        int flag = 0;
        for (int i = start; i < end; ++i) {
            if (num[i] == '0') {
                pzero = 1;
            } else {
                if (pzero == 1) {
                    printf(" %s", digit[0]);
                    pzero = 0;
                }
                if (i != 0) printf(" ");
                printf("%s", digit[num[i]-'0']);
                printf("%s", sunit[end-i-1]);
                flag = 1;
            }
        }
        if (flag == 1) printf("%s", bunit[(len-end)/4]);
    }
    if (len == 1 && num[0] == '0') printf("ling");
    printf("\n");
    return 0;
}
