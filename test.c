#include "test.h"

void printiarr(int* arr, LL l)
{
    for (int i = 0; i < l; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int* geniarr(LL l, int max)
{
    srand(time(NULL));
    int *ans = (int*) malloc(l * sizeof(int));

    printf("## generate random int array ##\n");
    for (int i = 0; i < l; ++i) {
        ans[i] = (rand() % (2 * max)) - max;
    }
    printiarr(ans, l);
    printf("###############################\n");
    return ans;
}

int main()
{
    int* arr = geniarr(10, 30);
    free(arr);
    arr = NULL;
    return 0;
}