#include <stdio.h>


int main(int argc, char const *argv[])
{
    int w, l;
    char c;
    scanf("%d %c", &w, &c);
    l = w >> 1;
    if (w & 1)
    {
        l += 1;
    }
    for (size_t i = 0; i < w; ++i)
    {
        printf("%c", c);
    }
    printf("\n");

    for (size_t i = 0; i < l - 2; ++i)
    {
        printf("%c", c);
        for (size_t i = 0; i < w -2; i++)
        {
            printf(" ");
        }
        
        printf("%c\n", c);
    }
    
    for (size_t i = 0; i < w; ++i)
    {
        printf("%c", c);
    }
    printf("\n");

    return 0;
}
