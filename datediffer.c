#include <stdio.h>

#define ISLEAP(x) ((((x)%4==0)&&((x)%100!=0))||((x)%400==0))

 int month[13][2] = {
        {0,0},
        {31,31},{28,29},{31,31},{30,30},
        {31,31},{30,30},{31,31},{31,31},
        {30,30},{31,31},{30,30},{31,31}};


int datediffer()
{
    int date1, date2;
    int year1, year2, month1, month2, day1, day2, i=1, sumy=0, sum1=0, sum2=0, k=0;
    scanf("%d", &date1);
    scanf("%d", &date2);
    if (date1 > date2) {
        int tmp = date1;
        date1 = date2;
        date2 = tmp;
    }
    year1 = date1/10000;
    year2 = date2/10000;
    month1 = date1/100 - year1*100;
    month2 = date2/100 - year2*100;
    day1 = date1%100;
    day2 = date2%100;
    while (year1 + i < year2) {
        sumy += 365;
        if (ISLEAP(year1 + i)) ++sumy;
        ++i;
    }
    i = 1;
    if (ISLEAP(year1)) k=1;
    while (month1 + i < 13) {
        sum1 += month[month1 + i][k];
        ++i;
    }
    sum1 = sum1 + month[month1][k] - day1 + 1;
    i = 1;
    if (!ISLEAP(year2)) k=0;
    while (month2 + i < 13) {
        sum2 += month[month2 + i][k];
        ++i;
    }
    sum2 = sum2 + month[month2][k] -day2 + 1;
    if (year1 == year2) {
        sumy = sumy + sum1 - sum2 + 1;
    }
    else {
        sumy = sumy + sum1 + 365 - sum2 + 1;
        if (k == 1) ++sumy;
    }
    printf("%d\n", sumy);
    return 0;
}
