#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int partner[100000];
int intend[100000] = {0};
vector<int> intender;
int main()
{
    int N, c1, c2;
    scanf("%d", &N);
    fill(partner, partner+100000, -1);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &c1, &c2);
        partner[c1] = c2;
        partner[c2] = c1;
    }
    scanf("%d", &N);
    intender.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(intender[i]));
        intend[intender[i]] = 1;
    }
    int count = 0;
    for (int i = 0; i < N; ++i) {
        int itr = intender[i];
        int ptr = partner[itr];
        if (ptr != -1 && intend[ptr] == 1) {
            intender[i] = 200000;
        } else {
            ++count;
        }
    }
    printf("%d\n", count);
    sort(intender.begin(), intender.end());
    for (int i = 0; i < count - 1; ++i) {
        printf("%05d ", intender[i]);
    }
    if (count > 0)
        printf("%05d\n", intender[count-1]);
    return 0;
}
