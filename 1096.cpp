#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int end = sqrt(N)+1, max = 0, start;
    for (int i = 2; i <= end; ++i) {
        if (N%i != 0) continue;
        int num = N, tmp;
        for (tmp = i; tmp <= end && num%tmp == 0; ++tmp) {
            num/=tmp;
        }
        if (tmp-i > max) {
            max = tmp-i;
            start = i;
        }
    }
    if (max == 0) {
        max = 1;
        start = N;
    }
    printf("%d\n", max);
    printf("%d", start);
    for (int i = 1; i < max; ++i) {
        printf("*%d", start+i);
    }
    printf("\n");
    return 0;
}
