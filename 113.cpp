#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) { return a < b; }

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> num(N);
    int S1 = 0, S2 = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(num[i]));
        S1 += num[i];
    }
    sort(num.begin(), num.end(), cmp);
    for (int i = 0; i < N / 2; ++i) {
        S2 += num[i];
    }
    printf("%d %d\n", N-N/2*2, S1-S2-S2);
    return 0;
}
