#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char names[40010][5];
bool cmp(int s1, int s2)
{
    return strcmp(names[s1], names[s2]) < 0;
}

int main()
{
    int sn, cn;
    scanf("%d %d", &sn, &cn);
    vector<int> namelist[cn+1];
    for (int i = 0; i < sn; ++i) {
        int a, b;
        scanf("%s %d", names[i], &a);
        for (int j = 0; j < a; ++j) {
            scanf("%d", &b);
            namelist[b].push_back(i);
        }
    }
    for (int i = 1; i <= cn; ++i) {
        printf("%d %lu\n", i, namelist[i].size());
        sort(namelist[i].begin(), namelist[i].end(), cmp);
        for (int s : namelist[i]) {
            printf("%s\n", names[s]);
        }
    }
    return 0;
}