#include <cstdio>

char card[] = {'S', 'H', 'C', 'D', 'J'};

int t;
int c1[54];
int c2[54];
int o[54];

void out(int nu)
{
    int i = nu / 13;
    int n = nu % 13;
    printf("%c%d", card[i], n+1);
}

int main()
{
    for (int i = 0; i < 54; ++i) {
        c1[i] = i;
    }
    scanf("%d", &t);
    for (int & j : o) {
        scanf("%d", &j);
    }
    int *arr[2] = {c1, c2};
    for (int k = 0; k < t; ++k) {
        int i2 = k%2;
        int i1 = 1 - i1;
        for (int j = 0; j < 54; ++j) {
            arr[i1][o[j]-1] = arr[i2][j];
        }
    }

    int ans = t % 2;
    int j = 0;
    while (j < 53) {
        out(arr[ans][j]);
        printf(" ");
        ++j;
    }
    out(arr[ans][j]);
    printf("\n");

    return 0;
}