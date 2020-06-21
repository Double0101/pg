#include <stdio.h>
#include <stdlib.h>


typedef struct MC {
    int volume;
    double price, pp;
} MC;

int cnum, weight;
MC *ms;

int cmp(void *a, void *b)
{
    return (((MC*)b)->pp > ((MC*)a)->pp);
}

int main()
{
    scanf("%d%d", &cnum, &weight);
    ms = (MC*) malloc(sizeof(MC) * cnum);
    for (int i = 0; i < cnum; ++i) {
        scanf("%d", &(ms[i].volume));
    }
    for (int j = 0; j < cnum; ++j) {
        scanf("%lf", &(ms[j].price));
        ms[j].pp = ms[j].price / (double) ms[j].volume;
    }

    qsort(ms, cnum, sizeof(MC), &cmp);

    double total = 0;
    for (int k = 0; k < cnum; ++k) {
        if (ms[k].volume < weight) {
            total += ms[k].price;
            weight -= ms[k].volume;
            continue;
        }
        total += ms[k].pp * weight;
        weight = 0;
    }
    printf("%.2lf\n", total);

    free(ms);
    return 0;
}