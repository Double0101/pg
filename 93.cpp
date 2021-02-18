#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char str[100005];

int main()
{
    cin.getline(str, 100005);
    int l = strlen(str);
    int tt = 0;
    for (int i = 0; i < l; ++i) {
        if (str[i] == 'T') ++tt;
    }
    int pp = 0, total = 0;
    for (int i = 0; i < l; ++i) {
        if (str[i] == 'T') --tt;
        if (str[i] == 'P') ++pp;
        if (str[i] == 'A') total = (total + (tt*pp)%1000000007)%1000000007;
    }
    printf("%d\n", total);

    return 0;
}
