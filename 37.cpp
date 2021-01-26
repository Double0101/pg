#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int i1, int i2)
{
    return i1 > i2;
}

int main()
{
    int N1, N2;
    scanf("%d", &N1);
    vector<int> coupon(N1);
    for (int i = 0; i < N1; ++i) {
        scanf("%d", &(coupon[i]));
    }
    scanf("%d", &N2);
    vector<int> prod(N2);
    for (int i = 0; i < N2; ++i) {
        scanf("%d", &(prod[i]));
    }
    sort(coupon.begin(), coupon.end(), cmp);
    sort(prod.begin(), prod.end(), cmp);
    int total = 0;
    for (int i = 0; i < N1 && i < N2 && coupon[i] > 0 && prod[i] > 0; ++i) {
        total += (coupon[i] * prod[i]);
    }
    int i = N1-1, j = N2-1;
    for (; i >= 0 && j >= 0 && coupon[i] < 0 && prod[j] < 0 ; --i, --j) {
        total += (coupon[i] * prod[j]);
    }
    printf("%d\n", total);
    return 0;
}