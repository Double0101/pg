#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int x = 1, y = -2;
    printf("%d %d\n", max(x, y), min(x, y));
    printf("%d %d\n", abs(x), abs(y));

    swap(x, y);
    printf("%d %d\n", x, y);

    int a[6] = {10, 11, 12, 13, 14, 15};
    reverse(a, a+4);
    for (int i = 0; i < 6; ++i)
        printf("%d ", a[i]);
    printf("\n");

    int b[10] = {1, 2, 3};
    do
    {
        printf("%d, %d, %d\n", b[0], b[1], b[2]);
    } while (next_permutation(b, b + 3));
    
    fill(b + 3, b + 10, 233);
    for (size_t i = 0; i < 10; ++i)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    
    return 0;
}