#include <stdio.h>

const int MAXN = 1000001;
int nums[1000001];

int M, N, n=0;

int main()
{
    scanf("%d %d", &M, &N);

    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 0;
    int o = 0;
    int m,v;
    for (int i = 0; i <= MAXN; ++i) {
        if (nums[i] == 0) {
            ++o;
            if (o == M) {
                m = i;
            }
            if (o == N) {
                v = i;
                break;
            }
            for (int j = 2*i; j < MAXN; j += i) {
                nums[j]=1;
            }
        }
    }
    int c = 0;
    for (int l = m; l <= v; ++l) {
        if (nums[l] == 0) {
            c = (c+1)%10;
            printf("%d", l);
            if (c != 0 && l != v)
                printf(" ");
            else
                printf("\n");
        }
    }

    return 0;
}