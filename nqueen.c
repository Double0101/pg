#include <stdio.h>
#include <stdbool.h>


int n;
int count = 0;
int *panel;
bool *hsm;

void pile(int sit)
{
    if (sit == n) {
        ++count;
        return;
    }
    int k;
    for (k = 0; k < n; ++k) {
        bool flag = false;
        if (hsm[k] == false) {
            flag = true;
            int f;
            for (f = 0; f < sit; ++f) {
                if (abs(f - sit) == abs(panel[f] - k)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                panel[sit] = k;
                hsm[k] = true;
                pile(sit + 1);
                hsm[k] = false;
            }
        }
    }
}

int nqueen()
{
    int i, num = 0;
    scanf("%d", &n);
    hsm = (bool*) malloc(sizeof(bool) * n);
    panel = (int*) malloc(sizeof(int) * n);
    while (num < n) {
        hsm[num++] = false;
    }
    pile(0);
    printf("%d\n", count);
    return 0;
}
