//
// Created by Double on 2019-11-03.
//

#include <stdio.h>


int n31()
{
    int in;
    int i = 0;
    scanf("%d", &in);
    while (in != 1) {
        ++i;
        if ((in & 1) == 1) {
            in = 3 * in + 1;
        }
        in >>= 1;
    }

    printf("%d\n", i);
    return 0;
}