#include <cstring>
#include <cstdio>

char s1[200], s2[200];
char ss1[200], ss2[200];
int N;

int main()
{
    scanf("%d%s%s", &N, s1, s2);
    int dot1 = strlen(s1), dot2 = strlen(s2);
    int l1 = dot1, l2 = dot2;
    for (int i = 0; i < l1; ++i) {
        if (s1[i] == '.') {
            dot1 = i;
            break;
        }
    }
    for (int i = 0; i < l2; ++i) {
        if (s2[i] == '.') {
            dot2 = i;
            break;
        }
    }
    int fv1 = 0, fv2 = 0;
    for (fv1 = 0; fv1 < l1 && (s1[fv1] == '0' || s1[fv1] == '.'); ++fv1);
    for (fv2 = 0; fv2 < l2 && (s2[fv2] == '0' || s2[fv2] == '.'); ++fv2);
    ss1[0] = ss2[0] = '0';
    ss1[1] = ss2[1] = '.';
    int pos = 2, i = 0, f1 = fv1, f2;
    while (i < N) {
        if (f1 < l1) {
            if (s1[f1] >= '0' && s1[f1] <= '9') {
                ss1[pos++] = s1[f1];
                ++i;
            }
            ++f1;
        } else {
            ss1[pos++] = '0';
            ++i;
        }
    }
    ss1[pos] = '\0';
    pos = 2, i = 0, f2 = fv2;
    while (i < N) {
        if (f2 < l2) {
            if (s2[f2] >= '0' && s2[f2] <= '9') {
                ss2[pos++] = s2[f2];
                ++i;
            }
            ++f2;
        } else {
            ss2[pos++] = '0';
            ++i;
        }
    }
    ss2[pos] = '\0';
    int e1 = dot1-fv1, e2 = dot2-fv2;
    if (fv1 == l1) e1 = 0;
    if (fv2 == l2) e2 = 0;
    if (e1 < 0) ++e1;
    if (e2 < 0) ++e2;
    if (strcmp(ss1, ss2) == 0 && e1 == e2) {
        printf("YES %s*10^%d\n", ss1, e1);
    } else {
        printf("NO %s*10^%d %s*10^%d\n", ss1, e1, ss2, e2);
    }
    return 0;
}
