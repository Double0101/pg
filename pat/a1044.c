#include <stdio.h>
#include <limits.h>

const int N = 100010;
int price, dnum;
int min = INT_MAX;

int upb(int* dias, int L, int R, int x)
{
    int left = L, right = R, mid;
    while (left < right) {
        mid = (left+right)/2;
        if (dias[mid] > x) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

    return left;
}

int main()
{
    int diamonds[N];
    scanf("%d %d", &dnum, &price);
    diamonds[0] = 0;
    for (int i = 1; i <= dnum; ++i) {
        scanf("%d", diamonds+i);
        diamonds[i] += diamonds[i-1];
    }

    for (int j = 1; j <= dnum; ++j) {
         int up = upb(diamonds, j, dnum+1, diamonds[j-1]+price);
         if (diamonds[up-1]-diamonds[j-1] == price) {
             min = price;
             break;
         }
         else if (up <= dnum && diamonds[up] - diamonds[j-1] < min) {
             min = diamonds[up] - diamonds[j-1];
         }
    }

    for (int k = 1; k <= dnum; ++k) {
        int up = upb(diamonds, k, dnum+1, diamonds[k-1]+min);
        if (diamonds[up-1]- diamonds[k-1] == min)
            printf("%d-%d\n", k, up-1);
    }
    return 0;
}
