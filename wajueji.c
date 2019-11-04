//
// Created by Double on 2019-11-03.
//

#include <stdio.h>


int main()
{
    int count, school = 100001, score = 0;
    int sumSores[100002] = {0};
    sumSores[school] = 0;
    scanf("%d", &count);
    while (count--) {
        int sno, ss;
        scanf("%d %d", &sno, &ss);
        sumSores[sno] += ss;
        if (sumSores[sno] > score)
        {
            school = sno;
            score = sumSores[sno];
        }
    }
    printf("%d %d\n", school, score);
}
