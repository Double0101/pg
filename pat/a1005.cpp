#include <stdio.h>
#include <string.h>

char codes[10][10] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
};
char nums[102];
int main()
{
    scanf("%s", nums);
    int i = 0, sum = 0;
    while (nums[i] != '\0') {
        sum += (int)(nums[i++] - '0');
    }
    memset(nums, '\0', 102);
    i = 101;
    if (sum == 0) {
        printf("zero\n");
        return 0;
    }
    while (sum > 0) {
        nums[i--] = sum % 10;
        sum = sum / 10;
    }
    i++;
    printf("%s", codes[nums[i++]]);
    for (; i < 102; ++i) {
        printf(" %s", codes[nums[i]]);
    }
    printf("\n");
    return 0;
}