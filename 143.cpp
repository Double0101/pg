#include <cstdio>
#include <unordered_map>

using namespace std;
int M, N;
int preorder[10000];
unordered_map<int, bool> m;
int main()
{
    scanf("%d%d", &M, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", preorder+i);
        m[preorder[i]] = true;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, r = -1;
        scanf("%d%d", &a, &b);
        if (m[a] == false && m[b] == false) {
            printf("ERROR: %d and %d are not found.\n", a, b);
            continue;
        }
        else if (m[a] == false || m[b] == false) {
            if (m[a] == false) printf("ERROR: %d is not found.\n", a);
            else printf("ERROR: %d is not found.\n", b);
            continue;
        }
        for (int j = 0; j < N; ++j) {
            int u = preorder[j];
            if ((u >= a && u <= b)
                || (u <= a && u >= b)) {
                r = j;
                break;
            }
        }
        if (preorder[r] == a) printf("%d is an ancestor of %d.\n", a, b);
        else if (preorder[r] == b) printf("%d is an ancestor of %d.\n", b, a);
        else printf("LCA of %d and %d is %d.\n", a, b, preorder[r]);
    }
    return 0;
}
