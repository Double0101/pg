#include <cstdio>

int start, rstart = -1, rpre, N, pre;
int next[100000];
int value[100000];
int map[10005] = {0};

inline
int abs(int i) { return i < 0 ? 0-i : i; }

void print(int start) {
    if (start == -1) return;
    int ns = start;
    while (ns != -1) {
        printf("%05d %d ", ns, value[ns]);
        if (next[ns] != -1) printf("%05d\n", next[ns]);
        else printf("-1\n");
        ns = next[ns];
    }
}

int main()
{
    scanf("%d%d", &start, &N);
    int a;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        scanf("%d %d", &(value[a]), &(next[a]));
    }
    int ns = next[start];
    pre = start;
    map[abs(value[start])] = 1;
    while (ns != -1) {
        if (map[abs(value[ns])] == 0) {
            map[abs(value[ns])] = 1;
            next[pre] = ns;
            pre = ns;
        } else {
            if (rstart == -1) {
                rstart = ns;
            } else {
                next[rpre] = ns;
            }
            rpre = ns;
        }
        int tmp = ns;
        ns = next[ns];
        next[tmp] = -1;
    }
    print(start);
    print(rstart);
    return 0;
}
