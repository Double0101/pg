#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <utility>

#define MAXN 7

typedef struct {
    int x,y;
} step;

int matrix[MAXN - 1][MAXN] = {{ 1, -1, -1, -1,  0,  0, -1},
                              { 0,  0, -1,  0,  0,  0,  0},
                              { 0,  0,  0,  0, -1,  0,  0},
                              { 0,  0,  0, -1, -1, -1,  0},
                              {-1, -1, -1,  0, -1,  0,  0},
                              {-1, -1, -1, -1,  0,  0,  0}};
int pass[MAXN - 1][MAXN] = {0};

inline
bool passed(int x, int y, int stepc)
{
    if (x < 0 || y < 0 || x >= MAXN - 1 || y >= MAXN) return false;
    bool b = matrix[x][y] == 0 && pass[x][y] == 0;
    if (b) {
        pass[x][y] = 1;
        matrix[x][y] = stepc + 1;
    }
    return b;
}

inline
step* make_step(int x, int y)
{
    step *ss = (step*) malloc(sizeof(step));
    ss->x = x;
    ss->y = y;
    return ss;
}

int main() {
    std::queue<step*> path;
    step *start = (step*) malloc(sizeof(step));
    start->x = 0;
    start->y = 0;
    path.push(start);

    while (!path.empty()) {
        step *s = path.front();
        int count = matrix[s->x][s->y];
        path.pop();
        if (passed(s->x, s->y + 1, count)) {
            step *ss = make_step(s->x, s->y + 1);
            path.push(ss);
        }
        if (passed(s->x + 1, s->y, count)) {
            step *ss = make_step(s->x + 1, s->y);
            path.push(ss);
        }
        if (passed(s->x, s->y - 1, count)) {
            step *ss = make_step(s->x, s->y - 1);
            path.push(ss);
        }
        if (passed(s->x - 1, s->y, count)) {
            step *ss = make_step(s->x - 1, s->y);
            path.push(ss);
        }
        int sx = s->x;
        int sy = s->y;
        free(s);
        if (sx == 5 && sy == 6) break;
    }
    while (!path.empty()) {
        step *ss = path.front();
        path.pop();
        free(ss);
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}