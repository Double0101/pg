#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char s[1001];

int main()
{
    cin.getline(s, 1001);
    int max = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int j = i+1;
        int flag1 = 1, flag2 = 1;
        for (int l = 0; l < len; ++l) {
            int a = i-l, b = j+l;
            if (flag1 == 1 && a >= 0 && b < len) {
                if (s[a] == s[b]) {
                    int ls = b-a+1;
                    if (ls > max) max = ls;
                } else flag1 = 0;
            } else flag1 = 0;
            a = i-l, b = i+l;
            if (a >= 0 && b < len) {
                if(s[a] == s[b]) {
                    int ls = b - a + 1;
                    if (ls > max) max = ls;
                } else flag2 = 0;
            } else flag2 = 0;
            if (flag1 == 0 && flag2 == 0) break;
        }
    }
    printf("%d\n", max);
    return 0;
}