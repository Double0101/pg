#include <cstdio>
#include <cstdlib>
#include <set>

int ROOT(int *bbs, int i)
{
    if (bbs[i] == i) return i;
    return ROOT(bbs, bbs[i]);
}

int main()
{
    int *smbbs;
    int a, b, m, n;
    std::set<int> as;
    scanf("%d %d", &a, &b);
    smbbs = (int*) malloc(sizeof(int) * a);
    for (int i = 0; i < a; ++i) {
        smbbs[i] = i;
    }
    for (int j = 0; j < b; ++j) {
        scanf("%d %d", &m, &n);
        smbbs[n] = ROOT(smbbs, m);
    }
    for (int i = 0; i < a; ++i) {
        as.insert(ROOT(smbbs, i));
    }
    printf("%d\n", as.size());
    return 0;
}