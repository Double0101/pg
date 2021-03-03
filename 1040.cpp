#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[1005];

int main()
{
    cin.getline(str, 1005);
    int max = 0, tmpl, start, end;
    for (int i = 0; i < strlen(str); ++i) {
        start = end = i;
        tmpl = 0;
        while (start >= 0 && end < strlen(str) && str[start] == str[end]) {
            tmpl = end-start+1;
            --start, ++end;
        }
        if (tmpl > max) max = tmpl;
        start = i, end = i+1;
        tmpl = 0;
        while (start >= 0 && end < strlen(str) && str[start] == str[end]) {
            tmpl = end-start+1;
            --start, ++end;
        }
        if (tmpl > max) max = tmpl;
    }
    printf("%d\n", max);
    return 0;
}
