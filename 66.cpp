#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int a;
    vector<int> pos(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a);
        pos[a] = i;
    }
    int i = 0, count = 0;
    while (i != N) {
        while (pos[0] != 0) {
            int owe = pos[0];
            pos[0] = pos[owe];
            pos[owe] = owe;
            ++count;
        }
        while (i < N && pos[i] == i) ++i;
        if (i != N) {
            pos[0] = pos[i];
            pos[i] = 0;
            ++count;
        }
    }
    printf("%d\n", count);
    return 0;
}