#include <cstdio>
#include <cstdlib>


int cn;
int *way;
int *ans;
int c;
int around = 0;

int main()
{

    scanf("%d", &cn);
    way = (int*) malloc(sizeof(int) * (cn+1));
    for (int i = 0; i < cn; ++i) {
        int l;
        scanf("%d", &l);
        around += l;
        way[i+1] = around;
    }

    scanf("%d", &c);
    ans = (int*) malloc(sizeof(int) * c);
    for (int j = 0; j < c; ++j) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }

        int dis = way[b-1] - way[a-1];
        ans[j] = dis;
        if (dis > around - dis)
            ans[j] = around - dis;
    }

    for (int k = 0; k < c; ++k) {
        printf("%d\n", ans[k]);
    }

    return 0;
}
