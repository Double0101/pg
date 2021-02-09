#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}
int i = 0;
void inorder(int root, int end, vector<int> &src, vector<int> &dst)
{
    if (root >= end) return;
    inorder(2*root+1, end, src, dst);
    dst[root] = src[i++];
    inorder(2*root+2, end, src, dst);
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> ns(N);
    vector<int> tree(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(ns[i]));
    }
    sort(ns.begin(), ns.end(), cmp);
    inorder(0, N, ns, tree);

    queue<int> q;
    printf("%d", tree[0]);
    if (1 < N) q.push(1);
    if (2 < N) q.push(2);
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        printf(" %d", tree[index]);
        if (N > index*2+1) q.push(index*2+1);
        if (N > index*2+2) q.push(index*2+2);
    }
    printf("\n");
    return 0;
}
