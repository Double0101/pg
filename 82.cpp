#include <cstdio>
#include <cstring>

using namespace std;

char num[12];
char art[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char unit[3][10] = {"\n", " Wan", " Yi"};
char subunit[4][10] = {"", " Shi", " Bai", " Qian"};

int main()
{
    scanf("%s", num);
    char *digits = num;
    if (digits[0] == '-') {
        printf("Fu ");
        ++digits;
    }
    int l = strlen(digits);
    if (l == 1 && digits[0] == '0') {
        printf("ling\n");
        return 0;
    }
    int start = 0, end = l - 1 - l/4*4, tail = l-1;
    char c = '\0';
    for ( ; end <= tail; start = end+1, end +=4) {
        int i = start;
        char pre;
        int flag = 0;
        while (i <= end) {
            pre = c;
            c = digits[i];
            if (c != '0') {
                flag = 1;
                if (i != 0) printf(" ");
                if (pre == '0') printf("ling ");
                printf("%s%s", art[c-'0'], subunit[end-i]);
            }
            ++i;
        }
        if (flag == 1)
            printf("%s", unit[(tail-end)/4]);
    }
    return 0;
}
