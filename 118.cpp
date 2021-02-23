#include <cstdio>
#include <algorithm>

using namespace std;

int father[10001];
int Father(int s)
{
    if (father[s] == s) return s;
    int f = Father(father[s]);
    father[s] = f;
    return f;
}
void Union(int s1, int s2)
{
    int f1 = Father(s1);
    int f2 = Father(s2);
    if (f1 != f2) father[f2] = f1;
}

int main()
{
    fill(father, father+10001, -1);
    int N, Q, n, b1, b2;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &n);
        if (n > 0) {
            scanf("%d", &b1);
            if (father[b1] == -1) father[b1] = b1;
        }
        for (int j = 1; j < n; ++j) {
            scanf("%d", &b2);
            if (father[b2] == -1) father[b2] = b2;
            Union(b1, b2);
        }
    }
    int t = 0, b = 0;
    for (int i = 0; i < 10001; ++i) {
        if (father[i] == -1) continue;
        ++b;
        if (Father(i) == i) ++t;
    }
    printf("%d %d\n", t, b);
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d%d", &b1, &b2);
        b1 = father[b1];
        b2 = father[b2];
        if (b1 == b2 && b1 != -1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}