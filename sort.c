#include <stdio.h>


int A[] = {4, 6, 1, 0, 13, -1, 23, 99, 13};

int selectSort()
{
    int size = sizeof(A) / sizeof(A[0]);
    int count = size - 1, i, j;
    for (i = 0; i < count; ++i) {
        int min = i;
        for (j = i; j < size; ++j) {
            if (A[min] > A[j]) {
                min = j;
            }
        }

        int tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
    }
    i = 0;
    while (i < size) {
        printf("%d ", A[i++]);
    }

    return 0;
}

int insertSort()
{
    int size = sizeof(A) / sizeof(A[0]);
    int i, j;
    for (i = 0; i < size; ++i) {
        int a = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > a) {
            A[j + 1] = A[j];
            j--;
        }
        A[++j] = a;
    }

    i = 0;
    while (i < size) {
        printf("%d ", A[i++]);
    }
}