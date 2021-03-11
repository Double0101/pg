#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;
vector<int> nextgroup;
vector<int> ss;
int N, capacity;
int main()
{
    scanf("%d%d", &N, &capacity);
    ss.resize(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &ss[i]);
    }
    int pre = -1;
    for (int i = 0; i < N; ++i) {
        if (i < capacity) q.push(-ss[i]);
        else {
            if (nextgroup.size() == capacity) {
                for (int j = 0; j < capacity; ++j) {
                    q.push(-nextgroup[j]);
                }
                nextgroup.clear();
                pre = -1;
                printf("\n");
            }
            if (ss[i] >= -q.top()) {
                q.push(-ss[i]);
            } else {
                nextgroup.push_back(ss[i]);
            }
            if (pre != -1) printf(" ");
            printf("%d", -q.top());
            pre = 1;
            q.pop();
        }
    }
    while (!q.empty()) {
        printf(" %d", -q.top());
        q.pop();
    }
    printf("\n");
    if (!nextgroup.empty()) {
        sort(nextgroup.begin(), nextgroup.end());
        printf("%d", nextgroup[0]);
        for (int i = 1; i < nextgroup.size(); ++i) {
            printf(" %d", nextgroup[i]);
        }
        printf("\n");
    }
    return 0;
}
