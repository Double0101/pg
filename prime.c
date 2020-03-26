#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int isPrime(int a)
{
    if (a <= 1) return 0;
    int s = sqrt(1.0 * a);
    for (int i = 2; i <= s; ++i)
    {
        if (!(a%i)) return 0;
    }
    return 1;
}

void findPrime(int max)
{
    for (int i = 0; i <= max; ++i) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
}

void eratosthenes(int max)
{
    char* c = (char*) malloc((max + 1) * sizeof(char));
    memset(c, 0, (max + 1) * sizeof(char));
    for (int i = 2; i < max; ++i) {
        if (c[i] == 1) continue;
        for (int j = i + i; j <= max; j += i) {
            c[j] = 1;
        }
    }
    for (int i = 2; i <= max; ++i) {
        if (c[i] == 0) printf("%d ", i);
    }
    printf("\n");
    free(c);
}

int main()
{
    findPrime(100);
    eratosthenes(100);
    return 0;
}