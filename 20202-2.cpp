#include <cstdio>
#include <vector>

using namespace std;

int N, money;

int main()
{
    scanf("%d%d", &N, &money);
    vector<int> price;
    price.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &price[i]);
    }
    int total = 0;
    for (int i = 0; i < N; ++i) {
        int tcost = 0, j;
        for (j = i; j < N; ++j) {
            tcost += price[j];
            if (tcost > money) break;
        }
        total += j-i;
    }
    printf("%d\n", total);
    return 0;
}
