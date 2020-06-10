#include <stdio.h>

int main()
{
    double ben = 1;
    char cs[3];
    for (int i = 0; i < 3; ++i) {
        double w, t, l;
        scanf("%lf%lf%lf", &w, &t, &l);
        double max = w;
        cs[i] = 'W';
        if (t > max) {
            max = t;
            cs[i] = 'T';
        }
        if (l > max) {
            max = l;
            cs[i] = 'L';
        }
        ben *= max;
    }

    ben = (ben*0.65f - 1)*2;
    printf("%c %c %c %.2lf\n", cs[0], cs[1], cs[2], ben);

    return 0;
}