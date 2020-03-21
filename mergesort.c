#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXL 100

typedef long long LL;

void merge(int *a, LL al)
{
    int tmp[MAXL] = {0};
    int *aa = a;
    int l = al/2;
    int *b = aa + l;
    int *ae = b;
    int *be = aa + al;
    int i = 0;
    if (al <= 1) {
        return;
    }
    merge(aa, l);
    merge(b, al - l);

    while (aa != ae && b != be) {
        if (*aa > *b) {
            tmp[i] = *b;
            ++b;
        } else {
            tmp[i] = *aa;
            ++aa;
        }
        ++i;   
    }
    while (aa != ae) {
        tmp[i++] = *aa;
        ++aa;
    }
    while (b != be) {
        tmp[i++] = *b;
        ++b;
    }    

    memcpy(a, tmp, al * sizeof(int));
}

int main()
{
    int arr[9] = {10, 15, 1, -2, 9, 32, 4, 99, 3};
    merge(arr, 9);
    for (int i = 0; i < 9; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}