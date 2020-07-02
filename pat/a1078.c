#include <stdio.h>

int ht[1000010] = {0};

int hsize;
int num;
int list[1000010];
int table[1000010] = {0};

int tablesize(int s)
{
    ht[0] = 1;
    ht[1] = 1;
    int ans = 2;
    int itn = 0;
    while (ans < s) {
        if (ht[itn] == 0) {
            ans = itn;
            for (int i = itn+itn; i <= 1000010; i += itn) {
                ht[i] = 1;
            }
        }
        ++itn;
    }
    return ans;
}

int hash(int n)
{
    for (int u = 0; u < hsize; ++u) {
        int h = (n+u*u)%hsize;
        if (table[h] == 0) {
            table[h] = n;
            return h;
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d", &hsize, &num);

    for (int i = 0; i < num; ++i) {
        scanf("%d", list+i);
    }
    hsize = tablesize(hsize);
    int a = hash(list[0]);
    if (a == -1) {
        printf("-");
    } else {
        printf("%d", a);
    }
    for (int j = 1; j < num; ++j) {
        a = hash(list[j]);
        printf(" ");
        if (a == -1) {
            printf("-");
        } else {
            printf("%d", a);
        }
    }


    return 0;
}