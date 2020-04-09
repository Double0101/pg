#include <cstdio>
#define MAXN 100

int weights[MAXN];
int value[MAXN];

int max = 0;
int weight;
int count;

int bagdfs(int index, int sum, int sumw)
{
    if (index == count) {
        if (sumw <= weight && sum > max)
            max = sum;
        return 0;
    }
    bagdfs(index + 1, sum + value[index], sumw + weights[index]);
    bagdfs(index + 1, sum, sumw);
    return 0;
}

int maxw()
{
    scanf("%d %d", &count, &weight);
    for (int i = 0; i < count; ++i) {
        scanf("%d %d", &weights[i], &value[i]);
    }
    bagdfs(0, 0, 0);
    int ans = max;
    max = 0;
    return ans;
}

int main()
{
    printf("%d\n", maxw());
    return 0;
}