#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int N, price;
    int min = INT_MAX;
    cin >> N >> price;
    vector<pair<int,int>> res;
    vector<int> chain(N);
    for (int i = 0; i < N; ++i) {
        cin >> chain[i];
    }
    int i = 0, j = -1, total = 0;
    while (j < N && i < N) {
        if (total < price) {
            ++j;
            if (j == N) break;
            total += chain[j];
        } else {
            total -= chain[i++];
        }
        if (total >= price) {
            if (total < min) {
                min = total;
                res.clear();
            }
            if (total == min) {
                res.push_back(make_pair(i, j));
            }
        }
    }
    for (auto it : res) {
        cout << it.first+1 << "-" << it.second+1 << endl;
    }
    return 0;
}
