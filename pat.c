#include <stdio.h>
#include <stdlib.h>


typedef struct candidate {
    char id[13];
    int score;
    int locnum;
    int locrank;
} candidate;

int candidate_cmp(candidate* c1, candidate* c2)
{
    if (c1 == c2) return 0;
    else {
        return c2->score - c1->score;
    }
}

candidate c[30000];
int num[300] = {0};

int main()
{
    int l, j, k = 0, i = 0;
    scanf("%d", &l);
    while (i < l) {
        scanf("%d", num[i]);
        for (j = 0; j < num[i]; ++j, ++k) {
            scanf("%s %d", candidate[k].id, &candidate[k].score);
        }
    }

    qsort(c, k, sizeof(candidate), candidate_cmp);



    return 0;
}



