#include <stdio.h>

char CODE[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C',
};
char ans[8];

void fill(char *start, int num) {
    start[0] = CODE[num/13];
    start[1] = CODE[num%13];
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ans[0] = '#';
    ans[7] = '\0';
    fill(ans+1, a);
    fill(ans+3, b);
    fill(ans+5, c);
    printf("%s\n", ans);
}