#include <stdio.h>
#include <stdlib.h>

int pool[10] = {0};

int cmp(void* a, void* b)
{
    return (*(int*)a) - (*(int*)b);
}

int main1()
{
    int i;
    for (i = 0; i < 10; ++i) 
    {
        scanf("%d", &pool[i]);
    }

    qsort(pool, 10, sizeof(int), &cmp);

    i = 0;
    while (pool[i] == 0 && i < 10)
        ++i;

    int tmp = pool[i];
    pool[i] = pool[0];
    pool[0] = tmp;
    for (i = 0; i < 10; ++i)
    {
        printf("%d", pool[i]);
    }
    printf("\n");
    
    return 0;
}

int main()
{
    int i, in;
    for (i = 0; i < 10; ++i)
    {
        scanf("%d", &in);
        ++pool[in];
    }
    i = 1;
    while (i < 10 && pool[i] == 0)
        ++i;

    printf("%d", i);
    --pool[i];

    for (i = 0; i < 10; ++i)
    {
        while (pool[i])
        {
            printf("%d", i);
            --pool[i];
        }
    }
    printf("\n");
    return 0;
}