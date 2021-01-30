#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;
    scanf("%d", &N);
    scanf("%d", &M);
    vector<int> favor(M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &favor[i]);
    }
    scanf("%d", &K);
    vector<int> give(K);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &give[i]);
    }

    return 0;
}