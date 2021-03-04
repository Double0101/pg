#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char digit[13][5] = {"tret", "jan", "feb", "mar", "apr",
                     "may", "jun", "jly", "aug",
                     "sep", "oct", "nov", "dec"};
char hdig[13][5] = {"", "tam", "hel", "maa", "huh",
                    "tou", "kes", "hei", "elo",
                    "syy", "lok", "mer", "jou"};
int main()
{
    char str[25], s1[5], s2[5];
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        cin.getline(str, 25);
        if (str[0] >= '0' && str[0] <= '9') {
            int c;
            sscanf(str, "%d", &c);
            int n1 = c/13;
            int n2 = c%13;
            if (n2 == 0 && n1 == 0) printf("%s\n", digit[0]);
            else if (n2 == 0) printf("%s\n", hdig[n1]);
            else if (n1 == 0) printf("%s\n", digit[n2]);
            else printf("%s %s\n", hdig[n1], digit[n2]);
        } else {
            int len = strlen(str);
            if (len > 5) {
                sscanf(str, "%s %s", s1, s2);
                int a = -1, b = -1;
                for (int j = 0; j < 13; ++j) {
                    if (strcmp(s1, hdig[j]) == 0) a = j;
                    if (strcmp(s2, digit[j]) == 0) b = j;
                }
                printf("%d\n", a*13+b);
            } else {
                int flag = 0;
                for (int j = 0; j < 13 && flag == 0; ++j) {
                    if (strcmp(str, digit[j]) == 0) {
                        flag = 1;
                        printf("%d\n", j);
                    }
                    if (strcmp(str, hdig[j]) == 0) {
                        flag = 1;
                        printf("%d\n", j*13);
                    }
                }
            }
        }
    }

    return 0;
}
