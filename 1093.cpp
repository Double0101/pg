#include <cstdio>
#include <cstring>
#include <iostream>
int main()
{
    char str[100005];
    std::cin.getline(str, 100005);
    int len = strlen(str);
    int total = 0;
    int tc = 0, pc = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'T') ++tc;
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] == 'T') --tc;
        else if (str[i] == 'P') ++pc;
        else if (str[i] == 'A'){
            total = (total+((tc*pc)%1000000007))%1000000007;
        }
    }
    printf("%d\n", total);
    return 0;
}