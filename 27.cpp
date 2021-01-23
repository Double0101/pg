#include <cstdio>

char ta[13] = {'0', '1', '2', '3',
               '4', '5', '6', '7',
               '8', '9', 'A', 'B', 'C'};

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    char cc[7];
    cc[0] = ta[a/13];
    cc[1] = ta[a%13];
    cc[2] = ta[b/13];
    cc[3] = ta[b%13];
    cc[4] = ta[c/13];
    cc[5] = ta[c%13];
    cc[7] = '\0';
    printf("#%s\n", cc);
    return 0;
}