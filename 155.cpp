#include <cstdio>
#include <vector>

using namespace std;

int lvorder[10001];
int N;
vector<int> oo;

void dfs(int root)
{
    if (root > N) return;
    oo.push_back(root);
    dfs(root*2+1);
    dfs(root*2);
    if (root*2 > N) {
        for (int i = 0; i < oo.size()-1; ++i) {
            printf("%d ", lvorder[oo[i]]);
        }
        printf("%d\n", lvorder[oo[oo.size()-1]]);
    }
    oo.pop_back();
}

int main()
{
    scanf("%d", &N);
    int maxn = 1, minn = 1;
    scanf("%d", lvorder+1);
    for (int i = 2; i <= N; ++i) {
        scanf("%d", lvorder+i);
        if (lvorder[i] > lvorder[i/2]) maxn = 0;
        if (lvorder[i] < lvorder[i/2]) minn = 0;
    }
    dfs(1);
    if (maxn == 0 && minn == 0) printf("Not Heap\n");
    else printf("%s Heap\n", maxn == 0 ? "Min" : "Max");
    return 0;
}
