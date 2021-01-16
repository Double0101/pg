#include <cstdio>
#include <cstdlib>

char s[3] = {'W', 'T', 'L'};
float f1[3], f2[3], f3[3];

int a=0,b=0,c=0;
float af, bf, cf, res;

int main()
{
    for (int i = 0; i < 3; ++i)
        scanf("%f", &f1[i]);
    for (int i = 0; i < 3; ++i)
        scanf("%f", &f2[i]);
    for (int i = 0; i < 3; ++i)
        scanf("%f", &f3[i]);
    af = f1[a], bf = f2[b], cf = f3[c];
    for (int i = 0; i < 3; ++i) {
        if (f1[i] > af)
            a = i, af = f1[i];
        if (f2[i] > bf)
            b = i, bf = f2[i];
        if (f3[i] > cf)
            c = i, cf = f3[i];
    }

    res = (af*bf*cf*0.65f) - 1;
    res *= 2;

    printf("%c %c %c %.2f\n", s[a], s[b], s[c], res);

    return 0;
}