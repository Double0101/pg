#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findmin(vector<int> vv)
{
    int min = 0;
    for (int i = 1; i < vv.size(); ++i) {
        for (int j = 0; j < vv.size(); ++j) {
            if (vv[(min+j)%vv.size()] == vv[(i+j)%vv.size()]) continue;
            if (vv[(min+j)%vv.size()] > vv[(i+j)%vv.size()]) {
                min = i;
            }
            break;
        }
    }
    vector<int> ans(vv.size());
    for (int i = 0; i < vv.size(); ++i) {
        ans[i] = vv[(min+i)%vv.size()];
    }
    return ans;
}

int main()
{
    vector<int> vi = {23,5,4};
    vi = findmin(vi);
    for (int i = 0; i < 3; ++i) {
        printf(" %d", vi[i]);
    }
    printf("\n");
    return 0;
}