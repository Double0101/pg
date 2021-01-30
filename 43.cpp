#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<int> pre, post;

bool isMirror = false;

void getpost(int root, int end) {
    if (root > end) return;
    int i = root+1, j = end;
    if (!isMirror) {
        while (i <= end && pre[i] < pre[root]) ++i;
        while (j > root && pre[j] >= pre[root]) --j;
    } else {
        while (i <= end && pre[i] >= pre[root]) ++i;
        while (j > root && pre[j] < pre[root]) --j;
    }
    if (i-j != 1) return;
    getpost(root+1, j);
    getpost(i, end);
    post.push_back(pre[root]);
}

int main()
{
    int N;
    cin >> N;
    pre.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> pre[i];
    }
    getpost(0, N-1);
    if (post.size() != N) {
        post.clear();
        isMirror = true;
        getpost(0, N-1);
    }
    if (post.size() != N) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << post[0];
        for (int i = 1; i < N; ++i) {
            cout << " " << post[i];
        }
        cout << endl;
    }
    return 0;
}
