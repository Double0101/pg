#include <stdio.h>
#include <stdlib.h>

int al, bl;
int mid, am, bm;
long *a, *b;

int main()
{
    scanf("%d", &al);
    a = (long*) malloc(sizeof(long)*al);
    for (int i = 0; i < al; ++i) {
        scanf("%ld", a+i);
    }
    scanf("%d", &bl);
    b = (long*) malloc(sizeof(long)*bl);
    for (int j = 0; j < bl; ++j) {
        scanf("%ld", b+j);
    }
    mid = (al+bl-1)/2;
    am = (al-1)/2;
    bm = (bl-1)/2;
    long *hp = a+am, *tp = b+bm;
    long *ml = hp-1;
    long *he = a+al-1, *th = b;
    int h = am-1;
    if (*hp > *tp) {
        long* tmp = hp;
        hp = tp;
        tp = tmp;
        he = b+bl-1;
        th = a;
        h = bm-1;
        ml = hp-1;
    }

    while (h != mid) {
        ++h;
        if (*hp < *th) {
            ml = hp;
            if (hp == he) {
                break;
            }
            ++hp;
        } else {
            ml = th;
            if (th == tp) {
                break;
            }
            ++th;
        }
    }

    if (h != mid) {
        ++h;
        if (ml == he) {
            ml = th;
        } else if (ml == tp) {
            ml = hp;
        }
    }

    while (h++!=mid) {
        ++ml;
    }
    printf("%ld\n", *ml);
    return 0;
}
