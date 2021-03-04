#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> ori, input;

int main()
{
    scanf("%d", &N);
    ori.resize(N);
    input.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ori[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &input[i]);
    }
    int i, j;
    for (i = 1; i < N && input[i] >= input[i-1]; ++i);
    for (j = i; j < N && input[j] == ori[j]; ++j);
    if (j == N) {
        printf("Insertion Sort\n");
        sort(input.begin(), input.begin()+i+1);
    } else {
        printf("Merge Sort\n");
        int flag = 1, span = 1;
        while (span < N && flag == 1) {
            flag = 0;
            for (int l = 0; l < N; ++l) {
                if (input[l] != ori[l]) {
                    flag = 1;
                }
            }
            span *= 2;
            for (int k = 0; k < N / span; ++k) {
                sort(ori.begin()+k*span, ori.begin()+(k+1)*span);
            }
            sort(ori.begin()+N/span*span, ori.end());
        }
        input = ori;
    }
    for (int k = 0; k < N - 1; ++k) {
        printf("%d ", input[k]);
    }
    printf("%d\n", input[N-1]);
    return 0;
}
