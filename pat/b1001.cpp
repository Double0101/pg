#include <cstdio>

int main()
{
    int num;
    scanf("%d", &num);

    int step = 0;
    while (num != 1) {
        if (num % 2 == 0)
            num /= 2;
        else {
            num = (3 * num + 1) / 2;
        }
        ++step;
    }
    printf("%d\n", step);

    return 0;
}