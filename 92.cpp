#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int num[256] = {0};
    char str2[1024];
    char str1[1024];
    cin.getline(str2, 1024);
    cin.getline(str1, 1024);
    int l = strlen(str1);
    for (int i = 0; i < l; ++i) {
        ++num[str1[i]];
    }
    l = strlen(str2);
    for (int i = 0; i < l; ++i) {
        --num[str2[i]];
    }
    int rc = 0, ec = 0;
    for (int i = 0; i < 256; ++i) {
        if (num[i] > 0) rc += num[i];
        else ec -= num[i];
    }
    if (rc == 0) {
        printf("Yes %d\n", ec);
    } else {
        printf("No %d\n", rc);
    }
    return 0;
}
