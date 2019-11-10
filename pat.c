#include <stdio.h>
#include <stdlib.h>


typedef struct candidate {
    char id[13];
    int score;
    int rank;
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
int num[100] = {0};

int pat()
{
    int l, j, k = 0, i = 0, rank = 1, lrank1[100] = {0}, lrank2[100] = {0}, lscore[100] = {0};
    scanf("%d", &l);
    while (i < l) {
        scanf("%d", &num[i]);
        int locnum = i + 1;
        for (j = 0; j < num[i]; ++j, ++k) {
            scanf("%s %d", c[k].id, &c[k].score);
            c[k].locnum = locnum;
        }
        ++i;
    }

    qsort(c, k, sizeof(candidate), candidate_cmp);

    for (i = 0; i < k; ++i) {
        c[i].rank = rank;
        if (rank > 1 && c[i].score == c[i - 1].score) {
            c[i].rank = c[i - 1].rank;
        }
        c[i].locrank = ++lrank1[c[i].locnum - 1];
        if (c[i].score != lscore[c[i].locnum - 1]) {
            lrank2[c[i].locnum - 1] = lrank1[c[i].locnum - 1];
            lscore[c[i].locnum - 1] = c[i].score;
        } else {
            c[i].locrank = lrank2[c[i].locnum - 1];
        }
        printf("%s %d %d %d\n", c[i].id, c[i].rank, c[i].locnum, c[i].locrank);
        ++rank;
    }

    return 0;
}



