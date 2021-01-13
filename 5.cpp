#include <cstdio>
#include <cstdlib>
#include <cstring>

char eng[10][10] = {"zero", "one", "two", "three", "four",
              "five", "six", "seven", "eight", "nine"};
char s[110];
int main()
{
    gets(s);
    int l = strlen(s);

    int a = 0;
    for (int i = 0; i < l; ++i) {
        a += s[i]-'0';
    }

    if (a == 0)
        printf("%s", eng[0]);

    int c = 1000;
    while (c > a) c /= 10;
    while (c != 0) {
        printf("%s", eng[a/c]);
        a = a%c;
        c /= 10;
        if (c != 0) printf(" ");
    }
    printf("\n");

    return 0;
}