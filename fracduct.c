#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Fraction {
    int up, down;
} Fraction;

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

Fraction* genFrac(int up, int down)
{
    Fraction* f = (Fraction*) malloc(sizeof(Fraction));
    f->up = up;
    f->down = down;
    return f;
}

void reduction(Fraction *fraction)
{
    int g = gcd(fraction->up, fraction->down);
    fraction->up /= g;
    fraction->down /= g;
}

void printFrac(Fraction *f)
{
    printf("Fraction: %d/%d\n", f->up, f->down);
}

int main()
{
    srand(time(NULL));
    int up = rand()%1000;
    int down = rand()%1000;
    Fraction* f = genFrac(up, down);
    printFrac(f);
    reduction(f);
    printFrac(f);

    return 0;
}