#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b)
{
    return !b ? a : gcd(b, a%b);
}

int main(){
    srand(time(NULL));
    int a = rand()%1000;
    int b = rand()%1000;

    printf("%d %d gcd %d\n", a, b, gcd(a, b));
}