#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> ropes(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(ropes[i]));
    }
    sort(ropes.begin(), ropes.end());
    double len = ropes[0];
    for (int i = 1; i < N; ++i) {
        len = (len+ropes[i])/2;
    }
    printf("%d", (int) len);
    return 0;
}
