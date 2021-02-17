#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) { return a < b; }

int main()
{
    int N, mn = 0;
    long long p;
    scanf("%d%lld", &N, &p);
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &(arr[i]));
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < N-mn; ++i) {
        for (int j = i+mn; j < N; ++j) {
            if (arr[j] <= arr[i]*p) {
                mn = j-i+1;
            } else {
                break;
            }
        }
    }
    printf("%d\n", mn);
    return 0;
}