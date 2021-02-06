#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int map[100001];
vector<int> stack;
void Pop()
{
    if (stack.size() == 0) printf("Invalid\n");
    else {
        printf("%d\n", stack[stack.size()-1]);
        --map[stack[stack.size()-1]];
        stack.pop_back();
    }
}
void PeekMedian()
{
    int ss = stack.size();
    if (ss == 0) {
        printf("Invalid\n");
        return;
    }
    ss = (ss+1)/2;
    int i = -1, n = 0;
    while (n < ss) {
        n += map[++i];
    }
    printf("%d\n", i);
}
void Push(int i)
{
    stack.push_back(i);
    ++map[i];
}

int main()
{
    int a,t;
    fill(map, map+100001, 0);
    scanf("%d", &t);
    char in[15];
    for (int i = 0; i < t; ++i) {
        scanf("%s", in);
        if (strcmp(in, "Pop") == 0) Pop();
        else if (strcmp(in, "PeekMedian") == 0) PeekMedian();
        else {
            scanf("%d", &a);
            Push(a);
        }
    }
    return 0;
}
