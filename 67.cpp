#include <cstdio>

using namespace std;

void gen(int src, int &n1, int &n2)
{
    int mm[10] = {0};
    for (int i = 3; i >= 0; --i) {
        ++mm[src%10];
        src /= 10;
    }
    n1 = 0;
    for (int i = 9; i >= 0; --i) {
        if (mm[i] == 0) continue;
        for (int j = 0; j < mm[i]; ++j) {
            n1 *= 10;
            n1 += i;
        }
    }
    n2 = 0;
    for (int i = 0; i < 10; ++i) {
        if (mm[i] == 0) continue;
        for (int j = 0; j < mm[i]; ++j) {
            n2 *= 10;
            n2 += i;
        }
    }
}

int main()
{
    int src, a, b, res = 0, pres = 9999;
    scanf("%d", &src);
    while (true) {
        gen(src, a, b);
        res = a-b;
        if (res == pres) break;
        printf("%04d - %04d = %04d\n", a, b, res);
        pres = res;
        src = res;
    }
    return 0;
}
