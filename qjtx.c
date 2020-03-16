/* 03.16.2020
 * partial greedy
 * Double0101
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Line {
    int x, y
} Line;

int cmp(Line *l1, Line *l2)
{
    return (l1->x) - (l2->x);
}

Line *lines;

int main()
{
    int i, j = 0, count, *rs;
    scanf("%d", &count);
    rs = (int*) malloc(count * sizeof(int));
    lines = (Line*) malloc(count * sizeof(Line));
    for (i = 0; i < count; ++i)
    {
        rs[i] = 0;
        scanf("%d%d", &lines[i].x, &lines[i].y);
    }
    qsort(lines, count, sizeof(Line), cmp);
    rs[0] = 1;
    for (i = 1; i < count; ++i)
    {
        if (lines[i].x >= lines[j].y)
        {
            rs[i] = 1;
            j = i;
            continue;
        }
        if (lines[i].y < lines[j].y)
        {
            rs[j] = 0;
            rs[i] = 1;
            j = i;
            continue;
        }
    }

    for (i = 0; i < count; ++i)
    {
        if (rs[i])
            printf("%d,%d\n", lines[i].x, lines[i].y);
    }
    return 0;
}

