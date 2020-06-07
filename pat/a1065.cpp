#include <cstdio>
#include <cstdlib>

int c;
int *ans;

int main()
{
    scanf("%d", &c);
    ans = (int*) malloc(sizeof(int) * c);
    for (int i = 0; i < c; ++i) {
        long a, b, d;
        scanf("%ld%ld%ld", &a, &b, &d);
        if (a > 0 && b > 0 && a+b < a) {
            ans[i] = 1;
            continue;
        }
        if (a < 0 && b < 0 && a+b > a) {
            ans[i] = 0;
            continue;
        }
        ans[i] = 0;
        if (a+b > d) {
            ans[i] = 1;
        }
    }

    for (int j = 0; j < c; ++j) {
        printf("Case #%d: ", j+1);
        if (ans[j])
            printf("true\n");
        else
            printf("false\n");
    }

    return 0;
}