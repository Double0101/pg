#include <stdio.h>
#include <string.h>

typedef long long LL;
LL map[256];

void init()
{
    for (char i ='0'; i <= '9'; ++i) {
        map[i] = i - '0';
    }
    for (char j = 'a'; j <= 'z'; ++j) {
        map[j] = j - 'a' + 10;
    }
}

LL c2ll(char *c, int l, int r, LL max)
{
    LL ans = 0;
    for (int i = 0; i < l; ++i) {
        ans = ans*r + map[c[i]];
        if (ans < 0 || ans > max) return -1;
    }
    return ans;
}

int cmp(char *n, int l, LL rad, LL max)
{
    LL num = c2ll(n, l, rad, max);
    if (num < 0) return 1;
    if (max > num) return -1;
    else if (max == num) return 0;
    else return 1;
}

int aaa(char *c, int l, LL low, LL high, LL max)
{
    LL mid;
    while (low <= high) {
        mid = (low + high) / 2;
        int flag = cmp(c, l, mid, max);
        if (flag == 0)
            return mid;
        else if (flag == -1) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

LL findLargestDigit(char *cs, int l)
{
    int ans = -1;
    for (int i = 0; i < l; ++i) {
        if (map[cs[i]] > ans)
            ans = map[cs[i]];
    }
    return ans+1;
}

char N1[20], N2[20], temp[20];
LL radix;
int tag;
LL ra;

int main()
{
    init();
    scanf("%s %s %d %lld", N1, N2, &tag, &radix);
    if (tag == 2) {
        strcpy(temp, N1);
        strcpy(N1, N2);
        strcpy(N2, temp);
    }
    ra = c2ll(N1, strlen(N1), radix, (1LL<<63)-1);
    LL lr = findLargestDigit(N1, strlen(N1));
    int high = (ra > lr) ? ra : lr;
    ++high;
    int ans = aaa(N2, strlen(N2), lr, high, ra);
    if (ans == -1)
        printf("Impossible\n");
    else
        printf("%lld\n", ans);
    return 0;
}