#include <cstdio>
#include <cstring>

using namespace std;

char ori[1500];
char rev[1500];
char sum[1500];

void reverse(char *src, char *dst)
{
    int len = strlen(src);
    char *s = dst;
    dst[len] = '\0';
    for (int i = len-1; i >= 0 ; --i) {
        *s = src[i];
        ++s;
    }
}
void add(char *n1, char *n2, char *s)
{
    int len = strlen(n1);
    s[len+1] = '\0';
    int start = len;
    int carry = 0;
    for (int i = len-1; i >= 0; --i) {
        s[start] = '0' + (n1[i]-'0'+n2[i]-'0'+carry)%10;
        carry = (n1[i]-'0'+n2[i]-'0'+carry)/10;
        --start;
    }
    s[start] = carry+'0';
    if (s[start] == '0') {
        while (s[start] != '\0') {
            s[start] = s[start+1];
            ++start;
        }
    }
}
int isPalind(char *s)
{
    int f = 1;
    int p1 = 0, p2 = strlen(s)-1;
    while (p1 < p2) {
        if (s[p1] != s[p2]) {
            f = 0;
            break;
        }
        ++p1, --p2;
    }
    return f;
}
int main()
{
    scanf("%s", ori);
    int flag = isPalind(ori);
    for (int i = 0; i < 10 && flag == 0; ++i) {
        reverse(ori, rev);
        add(ori, rev, sum);
        printf("%s + %s = %s\n", ori, rev, sum);
        flag = isPalind(sum);
        strcpy(ori, sum);
    }
    if (flag == 1) {
        printf("%s is a palindromic number.\n", ori);
    } else {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}


