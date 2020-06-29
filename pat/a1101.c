#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *arr, *min, *max;

int len;

int main()
{
    scanf("%d", &len);
    arr = (int*) malloc(sizeof(int)*len);
    min = (int*) malloc(sizeof(int)*len);
    max = (int*) malloc(sizeof(int)*len);

    for (int i = 0; i < len; ++i) {
        scanf("%d", arr+i);
    }
    int m = INT_MAX;
    for (int j = len-1; j >= 0; --j) {
        if (arr[j] < m) m = arr[j];
        min[j] = m;
    }
    m = INT_MIN;
    for (int k = 0; k < len; ++k) {
        if (arr[k] > m) m = arr[k];
        max[k] = m;
    }
    int c = 0;
    for (int l = 0; l < len; ++l) {
        if (min[l] == max[l]) ++c;
    }
    printf("%d\n", c);
    int a = 0;
    for (int n = 0; n < len; ++n) {
        if (min[n] == max[n]) {
            if (a != 0) {
                printf(" ");
            }
            printf("%d", min[n]);
            ++a;
        }
    }
    printf("\n");
    return 0;
}
