#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

void quicksort(int *a, LL l)
{
    if (l < 2) return;
    int pivot = *a;
    int *left = a, *right = a + l - 1;
    while (right > left)
    {
        while (right > left && *right > pivot) --right;
        *left = *right;
        while (right > left && *left < pivot) ++left;
        *right = *left;
    }
    *left = pivot;
    for (int i = 0; i < l; ++i) printf("%d ", a[i]);
    printf("\n");
    int lr = left - a;
    quicksort(a, lr);
    quicksort(left + 1, l - lr - 1);
}

int main()
{
    int arr[9] = {10, 15, 1, -2, 9, 32, 4, 99, 3};
    quicksort(arr, 9);
    for (int i = 0; i < 9; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}