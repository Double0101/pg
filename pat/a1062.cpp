#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Man {
    char ID[10];
    int talent, virtue;
    int total;
    int k;
} Man;

int num;
int cc = 0;
int th1, th2;
Man *ms;

int split(Man *m)
{
    if (m->talent >= th1 && m->virtue >= th1) return 3;
    if (m->virtue >= th1 && m->talent >= th2) return 2;
    if (m->virtue >= m->talent && m->talent >= th2) return 1;
    if (m->virtue < th2 || m->talent < th2) return -1;
    return 0;
}

int cmp(void *v1, void *v2)
{
    Man* m1 = (Man*) v1;
    Man* m2 = (Man*) v2;
    if (m1->k != m2->k) return m2->k - m1->k;
    if (m1->total != m2->total) return m2->total - m1->total;
    if (m1->virtue != m2->virtue) return m2->virtue - m1->virtue;
    return strcmp(m1->ID, m2->ID);
}

int main()
{
    scanf("%d%d%d", &num, &th2, &th1);
    ms = (Man*) malloc(sizeof(Man) * num);
    for (int i = 0; i < num; ++i) {
        Man* m = ms+i;
        scanf("%s %d %d", m->ID, &(m->virtue), &(m->talent));
        m->total = m->talent + m->virtue;
        m->k = split(m);
        if (m->k!=-1) ++cc;
    }

    qsort(ms, num, sizeof(Man), reinterpret_cast<int (*)(const void *, const void *)>(cmp));

    printf("%d\n", cc);
    for (int j = 0; j < cc; ++j) {
        if (ms[j].k!=-1) {
            printf("%s %d %d\n", ms[j].ID, ms[j].virtue, ms[j].talent);
        }
    }

    return 0;
}
/*
 * 14 60 80
10000001 75 79
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
 */