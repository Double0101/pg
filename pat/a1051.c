#include <stdio.h>
#include <string.h>

#define ISFILLED (size>capacity)
int capacity, N, K;

int size = 0;
int stack[1010];
int ans[1010];

void CLEAR()
{
    memset(stack, 0, sizeof(int)*1000);
    size = 0;
}

int main()
{
    scanf("%d %d %d", &capacity, &N, &K);
    for (int i = 0; i < K; ++i) {
        int n = 1; // next in
        int out;
        int top = 0;// top
        int flag = 0;
        int j;
        for (j = 0; j < N; ++j) {
            scanf("%d", &out);
            flag = 0;
            if (out != top && out >= n) {
                flag = 1;
                for (; n <= out; ++n) {
                    stack[size++] = n;
                }
                top = stack[size-1];
            }
            if (out == top) {
                flag = 1;
                if (ISFILLED) flag = 0; // false
                --size;
                top = stack[size-1];
            }
            if (flag == 0) {
                ++j;
                break;
            }
        }
        for (; j < N; ++j) {
            scanf("%d", &out);
        }
        ans[i] = flag;
        CLEAR();
    }
    for (int k = 0; k < K; ++k) {
        if (ans[k] == 0) printf("NO\n");
        if (ans[k] == 1) printf("YES\n");
    }

    return 0;
}