#include <cstdio>
#include <climits>

int count[10001] = {0};
int num[100000];

int N;

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", num+i);
        ++count[num[i]];
    }

    for (int i = 0; i < N; ++i) {
        if (count[num[i]] == 1) {
            printf("%d\n", num[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}