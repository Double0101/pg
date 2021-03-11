#include <cstdio>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    if (num < 2) return false;
    int end = sqrt(num);
    for (int i = 2; i <= end; ++i) {
        if (num%i == 0) return false;
    }
    return true;
}

int main()
{
    int date, mod = 100000000;
    char s[10], *p;
    bool flag = true;
    scanf("%s", s);
    p = s;
    sscanf(s, "%d", &date);
    while (mod > 1) {
        date = date%mod;
        printf("%s ", p++);
        if (isPrime(date)) printf("Yes\n");
        else {
            printf("No\n");
            flag = false;
        }
        mod /= 10;
    }
    if (flag) printf("All Prime!\n");
    return 0;
}
