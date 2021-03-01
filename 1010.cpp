#include <cstdio>
#include <cstring>

typedef long long LL;
char N1[2][15];
int tag, radix;

LL convert(int i, LL r)
{
    LL ans = 0;
    int len = strlen(N1[i]);
    for (int j = 0; j < len; ++j) {
        int b = 0;
        if (N1[i][j] >= '0' && N1[i][j] <= '9') b = N1[i][j]-'0';
        else b = 10+N1[i][j]-'a';
        ans = ans*r + b;
    }
    return ans;
}

int main()
{
    scanf("%s %s %d %d", N1[0], N1[1], &tag, &radix);
    LL aim = convert(tag - 1, radix);
    int other = 0;
    if (tag == 1) other = 1;
    int len = strlen(N1[other]), max = -1;
    for (int i = 0; i < len; ++i) {
        int r;
        if (N1[other][i] >= '0' && N1[other][i] <= '9') r = N1[other][i]-'0';
        else r = N1[other][i]-'a'+10;
        if (r > max) max = r;
    }
    LL minr = max+1, maxr = aim > minr ? aim : minr, mid, tmp;
    while (maxr >= minr) {
        mid = (maxr+minr)/2;
        tmp = convert(other, mid);
        if (tmp > aim || tmp < 0) maxr = mid-1;
        else if (tmp == aim) break;
        else minr = mid+1;
    }
    if (tmp != aim)
        printf("Impossible\n");
    else printf("%lld\n", mid);
    return 0;
}