#include <cstdio>
#include <cstring>

char src[100];
char rev[100];
char sum[100];
int N;

bool Palindromic(char *str)
{
    int len = strlen(str);
    int start = 0, end = len-1;
    while (start < end) {
        if (str[start] != str[end]) return false;
        ++start, --end;
    }
    return true;
}
void add(char *a, char *b, char *dst)
{
    int len = strlen(a);
    int carry = 0, num = len;
    dst[len+1] = '\0';
    for (int i = len-1; i >= 0; --i) {
        dst[num--] = '0' + (a[i]-'0'+b[i]-'0'+carry)%10;
        carry = (a[i]-'0'+b[i]-'0'+carry)/10;
    }
    dst[num] = '0'+carry;
    if (carry == 0) {
        for (int i = 0; i <= len; ++i) {
            dst[i] = dst[i+1];
        }
    }
}
void reverse(char *a, char *b)
{
    int len = strlen(a);
    b[len] = a[len];
    for (int i = 0; i < len; ++i) {
        b[i] = a[len-1-i];
    }
}
int main()
{
    scanf("%s %d", src, &N);
    int i;
    for (i = 0; i < N && !Palindromic(src); ++i) {
        reverse(src, rev);
        add(src, rev, sum);
        strcpy(src, sum);
    }
    printf("%s\n%d\n", src, i);
    return 0;
}
