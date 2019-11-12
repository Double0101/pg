#include <stdio.h>
#include <stdlib.h>


typedef struct mooncake {
    int price;
    int weight;
    double sprice;
} mooncake;

mooncake cake[1000];


int cakecmp(mooncake *m1, mooncake *m2)
{
    if (m2->sprice > m1->sprice) return 1;
    return -1;
}

int main()
{
    int count, suply, k = 0;
    double profit = 0;
    scanf("%d %d", &count, &suply);
    for (int i = 0; i < count; ++i) {
        scanf("%d", &cake[i].weight);
    }
    for (int j = 0; j < count; ++j) {
        scanf("%d", &cake[j].price);
        cake[j].sprice = (double) cake[j].price / (double) cake[j].weight;
    }
    qsort(cake, count, sizeof(mooncake), cakecmp);
    while (suply) {
        if (suply > cake[k].weight) {
            profit += cake[k].price;
            suply -= cake[k].weight;
        } else {
            profit += cake[k].sprice * suply;
            suply = 0;
        }
        ++k;
    }
    printf("%.2f\n", profit);
}
