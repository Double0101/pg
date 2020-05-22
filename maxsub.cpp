#include <iostream>

using namespace std;

int len;
int *arr;
int *amax;

int main()
{
    cin >> len;
    arr = (int*) malloc(sizeof(int) * len);
    memset(arr, 0, sizeof(int) * len);
    amax = (int*) malloc(sizeof(int) * len);
    memset(amax, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        cin >> arr[i];
    }

    amax[0] = arr[0];
    for (int j = 1; j < len; ++j) {
        amax[j] = arr[j];
        if (amax[j-1] + arr[j] > arr[j]) {
            amax[j] = amax[j-1] + arr[j];
        }
    }
    int maxv = amax[0];
    for (int k = 0; k < len; ++k) {
        if (amax[k] > maxv)
            maxv = amax[k];
    }

    cout << maxv << endl;
    return 0;
}