#include <stdio.h>

char n1[11];
char n2[11];
int tag;
int radix;

long long convert(char *a, long long r) {
    long long aim = 0;
    for (char *c = a; *c != '\0'; ++c) {
        aim *= r;
        if (*c >= '0' && *c <= '9') {
            aim += *c - '0';
        } else {
            aim += *c - 'a' + 10;
        }
    }
    return aim;
}

int main()
{
    scanf("%s %s %d %d", n1, n2, &tag, &radix);
    long long max = 0;
    char *a, *b;
    if (tag == 1) {
        a = n1;
        b = n2;
    }
    else {
        a = n2;
        b = n1;
    }

    long long aim = convert(a, radix);

    for (char *c = b; *c != '\0'; ++c) {
        int r;
        if (*c >= '0' && *c <= '9') {
            r = *c - '0';
        } else {
            r = *c - 'a' + 10;
        }
        if (r > max) max = r;
    }

    long long tar = 0;
    long long low = ++max, high = aim > low ? aim : low;
    long long mid;
    while (low <= high) {
        mid = (low+high)/2;
        tar = convert(b, mid);
        if (tar < 0 || tar > aim) high = mid-1;
        else if (tar == aim) break;
        else low = mid+1;
    }

    if (tar != aim) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", mid);
    }

    return 0;
}