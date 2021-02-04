#include <cstdio>
#include <map>

using namespace std;

map<int, int> colors;
int M,N,n,c;

int main()
{
    scanf("%d%d", &M, &N);
    n = N*M/2;
    for (int i = 0; i < N*M; ++i) {
        int a;
        scanf("%d", &a);
        if (colors.find(a) == colors.end()) colors[a] = 0;
        colors[a] += 1;
        if (colors[a] > n) c = a;
    }
    printf("%d\n", c);
    return 0;
}