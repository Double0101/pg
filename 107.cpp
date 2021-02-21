#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> father;
vector<int> hobby(1001, 0);
vector<int> cluster(1001, 0);
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
    if (f1 != f2) {
        father[f2] = f1;
    }
}
bool cmp(int a, int b) { return a > b; }
int main()
{
    scanf("%d", &N);
    father.resize(N+1);
    for (int i = 0; i <= N; ++i) {
        father[i] = i;
    }
    int hn, h;
    for (int i = 1; i <= N; ++i) {
        scanf("%d: ", &hn);
        for (int j = 0; j < hn; ++j) {
            scanf("%d", &h);
            if (hobby[h] != 0) {
                Union(hobby[h], i);
            } else {
                hobby[h] = i;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int f = Father(i);
        if (f == i) ++count;
        ++cluster[f];
    }
    printf("%d\n", count);
    sort(cluster.begin(), cluster.end(), cmp);
    for (int i = 0; i < count-1; ++i) {
        printf("%d ", cluster[i]);
    }
    printf("%d\n", cluster[count-1]);
    return 0;
}
