#include <cstdio>
#include <cstring>
bool isNum(char *s)
{
    int dn = 0, dp = -1, len = strlen(s);
    for (int i = s[0] == '-' ? 1 : 0; i < len; ++i) {
        if (s[i] == '.') {
            if (dn == 0) dp = i;
            ++dn;
            continue;
        }
        if (s[i] < '0' || s[i] > '9') return false;
    }
    if (dn > 1) return false;
    if (dn == 1 && len-dp > 3) return false;
    return true;
}

int main()
{
    int N;
    char str[1000];
    double total = 0, num;
    int count = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", str);
        bool in = isNum(str);
        if (in) {
            sscanf(str, "%lf", &num);
            in =  num >= -1000 && num <= 1000;
        }
        if (in) {
            total += num;
            ++count;
        } else {
            printf("ERROR: %s is not a legal number\n", str);
        }
    }
    printf("The average of %d number%s is ", count, count == 1 ?"":"s");
    if (count == 0) printf("Undefined\n");
    else printf("%.2lf\n", total/count);
    return 0;
}
