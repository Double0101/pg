#include <stdio.h>
#include <stdlib.h>

float p1[1001] = {0};
float p2[1001] = {0};
float res[2001] = {0};

int main()
{
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        int e;
        scanf("%d", &e);
        scanf("%f", &p1[e]);
    }
    scanf("%d", &K);
    for (int i = 0; i < K; ++i) {
        int e;
        scanf("%d", &e);
        scanf("%f", &p2[e]);
    }

    for (int i = 0; i < 1001; ++i) {
        for (int j = 0; j < 1001; ++j) {
            res[i+j] += (p1[i]*p2[j]);
        }
    }
    int count = 0;
    for (int i = 0; i < 2001; ++i) {
        if (res[i] != 0) ++count;
    }
    printf("%d", count);

    for (int i = 2000; i >= 0; --i) {
        if (res[i] != 0) {
            printf(" %d %.1f", i, res[i]);
        }
    }

    printf("\n");

    return 0;
}