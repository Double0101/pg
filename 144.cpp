#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> vi;

int main()
{
    int N, a;
    scanf("%d", &N);
    vi.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(vi[i]));
    }
    sort(vi.begin(), vi.end());
    int i = 0;
    while (vi[i] <= 0) ++i;
    if (i == N || vi[i] > 1) printf("1\n");
    else {
        int m = 1;
        for (; i < N; ++i) {
            if (vi[i] > m) {
                if (vi[i] == m+1) m=m+1;
                else {
                    printf("%d\n", m+1);
                    return 0;
                }
            }
        }
        printf("%d\n", vi[N-1]+1);
    }

    return 0;
}
