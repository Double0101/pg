#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 180

typedef struct factor {
    int x, cnt;
} factor;

int* primelist(int max)
{
    bool b[MAXN] = {false};
    b[0] = b[1] = true;
    for (int i = 2; i < max; ++i)
    {
        if (b[i] == true) continue;
        for (int j = i + i; j <= max; j += i)
        {
            b[j] = true;
        }
    }
    int count = 0;
    for (int i = 0; i <= max ; ++i)
        if (!b[i]) ++count;
    int *ans = (int*) malloc((count + 1) * sizeof(int));
    int *arr = ans;
    for (int k = 0; k < max; ++k) {
        if (!b[k]) {
            *arr = k;
            ++arr;
        }
    }
    *arr = 0;
    return ans;
}

int main()
{
    factor* res = (factor*) malloc(10 * sizeof(factor));
    int a = 180;
    scanf("%d", &a);
    int *primes = primelist(a);
    int *p = primes;
    factor* f = res;
    while (*p != 0) {
        if (a % (*p) != 0) {
            ++p;
            continue;
        }
        a /= (*p);
        if (f->x != (*p)) {
            ++f;
            f->x = (*p);
        }
        ++(f->cnt);
    }
    for (int i = 0; i < 10; ++i) {
        if (res[i].cnt) {
            if (i > 1) printf("*");
            if (res[i].cnt == 1) printf("%d", res[i].x);
            else printf("%d^%d", res[i].x, res[i].cnt);
        }
    }
    printf("\n");
    return 0;
}