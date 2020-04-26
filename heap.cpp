#include <cstdio>
#include <cstdlib>

#define LCHILD(a) (a*2 + 1)
#define RCHILD(a) (a*2 + 2)
#define PARENT(a) ((a+1)/2)

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//void format(int *arr, int i)
//{
//    if (i == 0) return;
//    if (PARENT(i) >= 0 && arr[i] > arr[PARENT(i)]) {
//        swap(&arr[i], &arr[PARENT(i)]);
//        format(arr, PARENT(i));
//    }
//}

void rebuild(int *arr, int index, int size)
{
    if (size < LCHILD(index) + 1) return;
    int j = LCHILD(index);
    if (size > RCHILD(index) && arr[RCHILD(index)] > arr[LCHILD(index)]) {
        ++j;
    }

    if (arr[index] < arr[j]) {
        swap(&arr[index], &arr[j]);
        rebuild(arr, j, size);
    }
}

void buildH(int *arr, int size)
{
    if (size <= 1) return;
    int ss = size - 1;
    for (int i = ss; i >= 0; --i) {
        rebuild(arr, i, size);
    }
}

void heapsort(int *arr, int size)
{
    for (int i = 0; i < size; ++i) {
        buildH(arr+i, size-i);
    }
    for (int j = 0; j < size; ++j) {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {85, 55, 82, 57, 68, 92, 99, 98, 66, 56};
    heapsort(arr, 10);
}