
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp0(int* a, int* b)
{
    return *a - *b;
}

int cmp1(int* a, int* b)
{
    return *b - *a;
}

void inarr(int a, int* arr)
{
    for (int i = 0; i < 4; ++i) {
        arr[i] = a%10;
        a /= 10;
    }
}

int tonum(int* arr) {
    int a = 0;
    for (int i = 3; i >= 0; --i) {
        a *= 10;
        a += arr[i];
    }
    return a;
}

void blackhole(int in)
{
    if (in == 6174) return;
    int arr[4];
    inarr(in, arr);
    qsort(arr, 4, sizeof(int), &cmp1);
    int small = tonum(arr);
    qsort(arr, 4, sizeof(int), &cmp0);
    int big = tonum(arr);
    int sub = big - small;
    printf("%d - %d = %d\n", big, small, sub);
    blackhole(sub);
}

int main()
{
    srand(time(NULL));
    int ran = rand()%10000;
    blackhole(ran);
    return 0;
}