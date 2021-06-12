#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char str[10005];
char sub[10005];

int main()
{
    scanf("%s", str);
    scanf("%s", sub);
    int strl = strlen(str);
    int subl = strlen(sub);
    int s = -1, e = 99999999;
    for (int i = 0; i < strl; ++i) {
        if (str[i] != sub[0]) continue;
        int start = i, flag, j;
        for (j = 0; j < subl; ++j) {
            flag = 0;
            for (; start < strl; ++start) {
                if (str[start] == sub[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) break;
        }
        if (flag == 0) break;
        else if (j == subl && start - i < e - s) {
            e = start, s = i;
        }
        ++start;
    }
    for (int i = s; i <= e; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
