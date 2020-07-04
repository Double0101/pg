#include <stdio.h>
#include <string.h>

int N;

int la, lb;

int aa, bb;
char A[128];
char SA[128];
char B[128];
char SB[128];

int ci(char *a, int l)
{
    int i = 0;
    for (; i < l; ++i) {
        if (a[i] == '.') break;
    }
    if (i > 1 || a[0] != '0')
        return i;
    i = 0;
    for (int j = 2; j < l; ++j) {
        if (a[j] == '0') {
            --i;
            if (j == l-1) return 0;
        }
        else break;
    }
    return i;
}

char* erase0(char *a, int l)
{
    int i;
    for (i = 0; i < l-1; ++i) {
        if (a[i] == '.') {
            --i;
            break;
        }
        if (a[i] != '0') break;
    }
    return a+i;
}

void convert(char *a, int l, char *ans, int p)
{
    strcpy(ans, "0.");
    int i = 0;
    while (a[i] == '.' || a[i] == '0' && i < l) ++i;
    int k = 2;
    for (; i < l && k < 2+p; ++i) {
        if (a[i] == '.') continue;
        ans[k++] = a[i];
    }
    for (; k < 2+p; ++k) {
        ans[k] = '0';
    }
    strcat(ans+k, "*10^");
}

int main()
{
    scanf("%d %s %s", &N, A, B);
    la = strlen(A);
    lb = strlen(B);
    char *aaa = erase0(A, la);
    char *bbb = erase0(B, lb);
    la = strlen(aaa);
    lb = strlen(bbb);
    aa = ci(aaa, la);
    bb = ci(bbb, lb);
    convert(aaa, la, SA, N);
    convert(bbb, lb, SB, N);
    if (strcmp(SA, SB) == 0 && aa == bb) {
        printf("YES %s%d\n", SA, aa);
    } else {
        printf("NO %s%d %s%d\n", SA, aa, SB, bb);
    }

    return 0;
}