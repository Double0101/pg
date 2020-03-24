#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

int quickselect(int *a, LL al, LL aim)
{
    int pivot = *a;
    int *right = a;
    int *left = a + al - 1;
    while(left > right) {
        while (*left >= pivot && left > right) --left;
        *right = *left;
        while (*right < pivot && left > right) ++right;
        *left = *right;
    }
    *left = pivot;
    int nol = left - a + 1;
    if (nol > aim) return quickselect(a, nol - 1, aim);
    else if (nol < aim) return quickselect(left + 1, al - nol, aim - nol);
    else return pivot;
}

int main()
{
    int arr[9] = {10, 15, 1, -2, 9, 32, 4, 99, 3};
    printf("%d\n", quickselect(arr, 9, 1));
    return 0;
}