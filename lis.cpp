#include <iostream>

using namespace std;

int len;
int *arr;
int *ms;

int main()
{
    cin >> len;
    arr = (int*) malloc(sizeof(int) * len);
    ms = (int*) malloc(sizeof(int) * len);
    memset(ms, 0, sizeof(int) * len);

    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }
    ms[0] = 1;

    int ans = 1;
    for (int j = 1; j < len; ++j) {
        for (int i = 0; i < j; ++i) {
            if (arr[i] <= arr[j] && ms[i] + 1 > ms[j]) {
                ms[j] = ms[i] + 1;
            }
        }
        if (ms[j] > ans) {
            ans = ms[j];
        }
    }

    cout << ans << endl;

    return 0;
}