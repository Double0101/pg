#include <cstdio>

int bb[45];
int N;
int radix;

int convert(int n, int r)
{
    int i = 0;
    for (i = 0; n != 0; ++i) {
        bb[i] = n%r;
        n = n/r;
    }
    return i-1;
}

int main()
{
    scanf("%d%d", &N, &radix);
    int bound = convert(N, radix);
    int i = 0, e = bound;
    int flag = 0;
    while (i < e) {
        if (bb[i] != bb[e]) {
            flag = 1;
            break;
        }
        ++i, --e;
    }
    if (flag) printf("No\n");
    else printf("Yes\n");
    printf("%d", bb[bound]);
    for (int j = bound-1; j >= 0; --j) {
        printf(" %d", bb[j]);
    }
    printf("\n");
    return 0;
}