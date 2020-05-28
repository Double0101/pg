#include <cstdio>
#include <climits>
#include <iostream>
#include <cstdlib>

bool *vis;
int **G;
int *dp;
int cnum;
int rnum;

int main()
{
    scanf("%d %d", &cnum, &rnum);
    vis = (bool*) malloc(sizeof(bool) * cnum);
    dp = (int*) malloc(sizeof(int) * cnum);
    std::fill(dp, dp+cnum, INT_MIN);
    std::fill(vis, vis+cnum, false);
    G = (int**) malloc(sizeof(int*) * cnum);
    for (int i = 0; i < cnum; ++i) {
        G[i] = (int*) malloc(sizeof(int) * cnum);
        int* g = G[i];
        std::fill(g, g+cnum, INT_MAX);
    }

    for (int j = 0; j < rnum; ++j) {
        int c1, c2, l;
        scanf("%d %d %d", &c1, &c2, &l);
        G[c1][c2] = l;
    }

    return 0;
}