#include <cstdio>
#include <cstring>

int stucnt;
char mname[11], fname[11], tname[11];
char g;
char mid[11], fid[11], tmp[11];
int mscore = 101, fscore = -1, tscore;

int main()
{
    scanf("%d", &stucnt);
    for (int i = 0; i < stucnt; ++i) {
        scanf("%s %c %s %d", tname, &g, tmp, &tscore);
        if (g == 'F') {
            if (tscore > fscore) {
                strcpy(fname, tname);
                strcpy(fid, tmp);
                fscore = tscore;
            }
        } else {
            if (tscore < mscore) {
                strcpy(mname, tname);
                strcpy(mid, tmp);
                mscore = tscore;
            }
        }
    }
    if (fscore != -1) {
        printf("%s %s\n", fname, fid);
    } else {
        printf("Absent\n");
    }
    if (mscore != 101) {
        printf("%s %s\n", mname, mid);
    } else {
        printf("Absent\n");
    }

    if (fscore != -1 && mscore != 101) {
        printf("%d\n", fscore - mscore);
    } else {
        printf("NA\n");
    }

    return 0;
}
