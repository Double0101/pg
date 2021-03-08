#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

LL convert(char *num, LL r)
{
    int len = strlen(num);
    LL ans = 0;
    for (int i = 0; i < len; ++i) {
        if (num[i] >= '0' && num[i] <= '9') {
            ans = ans*r + num[i]-'0';
        } else {
            ans = ans*r + num[i]-'a'+10;
        }
    }
    return ans;
}

int main()
{
    char N1[15], N2[15];
    int tag;
    LL radix;
    scanf("%s %s %d %lld", N1, N2, &tag, &radix);
    char *aim = tag == 1 ? N2 : N1;
    LL dest = convert(tag == 1 ? N1 : N2, radix);
    LL low = 1, tmp;
    int len = strlen(aim);
    for (int i = 0; i < len; ++i) {
        if (aim[i] >= '0' && aim[i] <= '9')
            tmp = aim[i]-'0';
        else tmp = aim[i]-'a'+10;
        if (tmp > low) low = tmp;
    }
    LL high = max(dest, ++low);
    while (low <= high) {
        LL rr = (low+high)/2;
        LL cl = convert(aim, rr);
        if (cl == dest) {
            printf("%lld\n", rr);
            return 0;
        }
        if (cl < 0 || cl > dest) high = rr-1;
        else if (cl < dest) low = rr+1;
    }
    printf("Impossible\n");
    return 0;
}
