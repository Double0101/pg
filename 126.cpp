#include <cstdio>

using namespace std;
int degree[501] = {0};
int father[501];
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

int N, M;
int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i <= N; ++i) {
        father[i] = i;
    }
    int v1, v2;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &v1, &v2);
        ++degree[v1];
        ++degree[v2];
        Union(v1, v2);
    }
    int circuit = 0;
    int odddegree = 0;
    for (int i = 1; i <= N; ++i) {
        if (Father(i) == i) ++circuit;
        if (degree[i]%2 == 1) ++odddegree;
        if (i != 1) printf(" ");
        printf("%d", degree[i]);
    }
    printf("\n");
    if (circuit == 1) {
        if (odddegree == 0)
            printf("Eulerian\n");
        else if (odddegree == 2)
            printf("Semi-Eulerian\n");
        else
            printf("Non-Eulerian\n");
    } else printf("Non-Eulerian\n");

    return 0;
}
