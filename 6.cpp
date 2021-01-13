#include <cstdio>
#include <cstring>

char tname[20];
char ename[20];
char lname[20];
int th1,tm1,ts1, th2, tm2, ts2;
int eh=25,em=61,es=61;
int lh=0,lm=0,ls=0;

int main()
{
    int i;
    scanf("%d", &i);
    for (; i > 0; --i) {
        scanf("%s %d:%d:%d %d:%d:%d", tname, &th1, &tm1, &ts1, &th2, &tm2, &ts2);
        if (th1 < eh
            || (th1 == eh && tm1 < em)
            || (th1 == eh && tm1 == em && ts1 < es)) {
            eh = th1, em = tm1, es = ts1;
            strcpy(ename, tname);
        }
        if (th2 > lh
            || (th2 == lh && tm2 > lm)
            || (th2 == lh && tm2 == lm && ts2 > ls)) {
            lh = th2, lm = tm2, ls = ts2;
            strcpy(lname, tname);
        }
    }

    printf("%s %s\n", ename, lname);

    return 0;
}