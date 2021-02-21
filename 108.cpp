#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char str[100];

bool legal(char *s)
{
    int len = strlen(s);
    if (len > 8) return false;
    if (s[0] != '-' && s[0] != '.' && (s[0] < '0' || s[0] > '9')) return false;
    int don = 0, dop, f = 0;
    if (s[0] == '-') f = 1;
    if (s[0] == '.') don = 1, dop = 0;
    for (int i = 1; i < len; ++i) {
        if (str[i] == '.') {
            ++don;
            dop = i;
            continue;
        }
        if (s[i] < '0' || s[i] > '9') return false;
    }
    if (don > 1 || (don == 1 && dop != len-2 && dop != len-3 && dop != len-1)) return false;
    return true;
}

int main()
{
    int N, count = 0;
    double total = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s", str);
        if (!legal(str)) printf("ERROR: %s is not a legal number\n", str);
        else {
            double fff = atof(str);
            if (fff >= -1000 && fff <= 1000) {
                total += atof(str);
                ++count;
            }
            else printf("ERROR: %s is not a legal number\n", str);
        }
    }
    printf("The average of %d number%s is ", count, count==1?"":"s");
    if (count == 0) printf("Undefined\n");
    else printf("%.2lf\n", total/count);
    return 0;
}
