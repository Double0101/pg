#include <cstdio>

char latter[5] = {'S', 'H', 'C', 'D', 'J'};

int rTime;
int cards1[54];
int cards2[54];
int order[54];

inline
void printCard(int n)
{
    printf("%c%d", latter[n/13], n%13+1);
}

int main()
{
    for (int i = 0; i < 54; ++i) {
        cards1[i] = i;
    }
    scanf("%d", &rTime);
    int *a = cards1;
    int *b = cards2;
    for (int i = 0; i < 54; ++i) {
        scanf("%d", order+i);
        --order[i];
    }
    while (rTime-- > 0) {
        for (int i = 0; i < 54; ++i) {
            b[order[i]] = a[i];
        }
        int *tmp = a;
        a = b;
        b = tmp;
    }

    printCard(a[0]);
    for (int i = 1; i < 54; ++i) {
        printf(" ");
        printCard(a[i]);
    }
    printf("\n");
    return 0;
}
