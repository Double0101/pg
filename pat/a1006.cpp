#include <cstdio>

struct Sign {
    char IN[16];
    int h, m, s;
} fi, lo, tmp;

int c;

bool bigger(struct Sign s1, struct Sign s2) {
    if (s2.h != s1.h) return s2.h < s1.h;
    if (s2.m != s1.m) return s2.m < s1.m;
    return s2.s < s1.s;
}

int main()
{
    scanf("%d", &c);
    fi.h = fi.m = fi.s = 60;
    lo.h = lo.m = lo.s = 0;

    for (int i = 0; i < c; ++i) {
        scanf("%s %d:%d:%d", &(tmp.IN), &(tmp.h), &(tmp.m), &(tmp.s));
        if (bigger(fi, tmp)) {
            fi = tmp;
        }
        scanf("%d:%d:%d", &(tmp.h), &(tmp.m), &(tmp.s));
        if (bigger(tmp, lo)) {
            lo = tmp;
        }
    }

    printf("%s %s\n", fi.IN, lo.IN);

    return 0;
}