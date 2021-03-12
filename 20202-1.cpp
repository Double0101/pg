#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> weight, milkl, milkr;

int main()
{
    scanf("%d", &N);
    weight.resize(N);
    milkl.resize(N);
    milkr.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &weight[i]);
    }
    milkl[0] = 2;
    for (int i = 1; i < N; ++i) {
        if (weight[i] > weight[i-1]) milkl[i] = milkl[i-1]+1;
        else if (weight[i] == weight[i-1]) milkl[i] = milkl[i-1];
        else milkl[i] = 2;
    }
    milkr[N-1] = 2;
    for (int i = N-2; i >= 0; --i) {
        if (weight[i] > weight[i+1]) milkr[i] = milkr[i+1]+1;
        else if (weight[i] == weight[i+1]) milkr[i] = milkr[i+1];
        else milkr[i] = 2;
    }
    int total = 0;
    for (int i = 0; i < N; ++i) {
        total += max(milkr[i], milkl[i])*100;
    }
    printf("%d\n", total);
    return 0;
}
