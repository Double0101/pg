#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
    int address, data, next;
    Node(int a, int b, int c): address(a), data(b), next(c) {}
} node;

int data[100000];
int nxt[100000];
vector<node> list;
vector<int> result;
int start, N, K;

int main()
{
    scanf("%d%d%d", &start, &N, &K);
    int a, b, c;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        data[a] = b;
        nxt[a] = c;
    }
    int n = start;
    while (n != -1) {
        list.emplace_back(n, data[n], nxt[n]);
        n = nxt[n];
    }
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].data < 0) result.push_back(i);
    }
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].data >= 0 && list[i].data <= K) result.push_back(i);
    }
    for (int i = 0; i < list.size(); ++i) {
        if (list[i].data > K) result.push_back(i);
    }
    printf("%05d %d ", list[result[0]].address, list[result[0]].data);
    for (int i = 1; i < result.size(); ++i) {
        printf("%05d\n%05d %d ", list[result[i]].address, list[result[i]].address, list[result[i]].data);
    }
    printf("-1\n");
    return 0;
}
