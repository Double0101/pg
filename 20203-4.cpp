#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> reactant, product;
int react[100][101];
int N, M;
int main()
{
    scanf("%d", &N);
    reactant.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &reactant[i]);
    }
    scanf("%d", &M);
    product.resize(M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &product[i]);
    }
    for (int i = 0; i < 100; ++i) {
        fill(react[i], react[i]+101, 0);
    }

    return 0;
}
