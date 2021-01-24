#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[100];
char space[100];
int len;

int main()
{
    scanf("%s", str);
    len = strlen(str);
    int N = len+2;
    int l;
    for (int i = 1; i < len; ++i) {
        int n2 = N - 2*i;
        if (n2 < i) break;
        l = n2;
    }
    for (int i = 0; i < l - 2; ++i) {
        space[i] = ' ';
    }
    space[l-2] = '\0';
    int n = (len-l)/2;
    for (int i = 0; i < n; ++i) {
        printf("%c%s%c\n", str[i], space, str[len-1-i]);
    }
    for (int i = n; i < n+l; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
