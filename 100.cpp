#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char ldigits[13][5] = {"tret", "jan", "feb", "mar",
                       "apr", "may", "jun", "jly",
                       "aug", "sep", "oct", "nov", "dec"};
char hdigits[13][5] = {"", "tam", "hel", "maa",
                       "huh", "tou", "kes", "hei",
                       "elo", "syy", "lok", "mer", "jou"};
char str[20];
void func1(int num)
{
    if (num/13) printf("%s", hdigits[num/13]);
    if ((num/13) && (num%13)) printf(" ");
    if (num%13 || num == 0) printf("%s", ldigits[num%13]);
    printf("\n");
}
void func2()
{
    char *s1 = str, *s2 = str;
    int len = strlen(str);
    if (len > 4) {
        str[3] = '\0';
        s1 = str+4;
    }
    int a=0, b=0;
    for (int i = 0; i < 13; ++i) {
        if (strcmp(s1, ldigits[i]) == 0) a = i;
        if (strcmp(s2, hdigits[i]) == 0) b = i;
    }
    printf("%d\n", 13*b+a);
}

int main()
{
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        cin.getline(str, 20);
        if (str[0] >= '0' && str[0] <= '9') {
            func1(stoi(str));
        } else {
            func2();
        }
    }
    return 0;
}
