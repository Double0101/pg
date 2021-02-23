#include <cstdio>
#include <cstring>
int N;
int num[40] = {0};
char nstr[10];

int main()
{
    scanf("%d", &N);
    int len, id;
    for (int i = 0; i < N; ++i) {
        id = 0;
        scanf("%s", nstr);
        len = strlen(nstr);
        for (int j = 0; j < len; ++j) {
            id += (nstr[j]-'0');
        }
        num[id] = 1;
    }
    int pn = 0;
    int count = 0;
    for (int i = 0; i < 40; ++i) {
        count += num[i];
    }
    printf("%d\n", count);
    for (int i = 0; i < 40; ++i) {
        if (num[i] == 0) continue;
        if (pn++ != 0) printf(" ");
        printf("%d", i);
    }
    printf("\n");
    return 0;
}
