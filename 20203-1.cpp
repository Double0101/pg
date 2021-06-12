#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int fib[10001];

int fibonacci(int i)
{
    if (fib[i] == -1) {
        int f = fibonacci(i-1) + fibonacci(i-2);
        fib[i] = f;
    }
    return fib[i];
}


int main()
{
    fill(fib, fib+10001, -1);
    scanf("%d", &N);
    fib[0] = 0, fib[1] = 1;
    int i = 0;
    while (fibonacci(i) < N) ++i;
    int dif1 = fibonacci(i)-N, dif2 = N-fibonacci(i-1);
    printf("%d\n", dif1 < dif2 ? fibonacci(i) : fibonacci(i-1));
    return 0;
}