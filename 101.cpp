#include <cstdio>

int N;
int arr[100000];
int mar[100000];
int mir[100000];
int main()
{
    scanf("%d", &N);
    int max = -1;
    for (int i = 0; i < N; ++i) {
        scanf("%d", arr+i);
        if (arr[i] > max) {
            max = arr[i];
        }
        mar[i] = max;
    }
    int min = 1000000000;
    int start = N;
    int count = 0;
    for (int i = N-1; i >= 0; --i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        mir[i] = min;
        if (arr[i] == mar[i] && arr[i] == mir[i]) {
            ++count;
            start = i;
        }
    }
    printf("%d\n", count);
    if (count > 0) {
        printf("%d", arr[start]);
        for (int i = start+1; i < N; ++i) {
            if (arr[i] == mar[i] && arr[i] == mir[i])
                printf(" %d", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
