#include <cstdio>


char s1[65], s2[65], s3[65], s4[65];
char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};


int main()
{
    scanf("%s%s%s%s", s1, s2, s3, s4);
    int i = 0, d, h;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
            d = s1[i] - 'A';
            ++i;
            break;
        }
        ++i;
    }
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            if (s1[i] >= '0' && s1[i] <= '9') {
                h = s1[i] - '0';
                break;
            } else if (s1[i] >= 'A' && s1[i] <= 'N') {
                h = s1[i] - 'A' + 10;
                break;
            }
        }
        ++i;
    }
    i = 0;
    while (s3[i] != '\0' && s4[i] != '\0') {
        if (s3[i] == s4[i]) {
            if ((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z'))
                break;
        }
        ++i;
    }
    printf("%s %02d:%02d\n", week[d], h, i);
    return 0;
}