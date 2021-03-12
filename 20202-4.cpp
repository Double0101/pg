#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, pair<int, int>>>> m;
vector<int> pre;
vector<int> ts, tv;
vector<int> indge, tmpin;
vector<bool> visit;
int N, M, num;
const int inf = 999999999;
bool consist = true;

void print(int r)
{
    if (pre[r] != -1) {
        print(pre[r]);
    }
    if (num++ != 0) printf("->");
    printf("%d", r);
}

int main()
{
    scanf("%d%d", &N, &M);
    indge.resize(N, 0);
    tmpin.resize(N+1, 0);
    m.resize(N+1);
    int a, b, c, d;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ++indge[b], ++tmpin[b];
        m[a].push_back(make_pair(b, make_pair(c, d)));
    }
    for (int i = 0; i < N; ++i) {
        if (indge[i] == 0) {
            ++tmpin[i];
            m[N].push_back(make_pair(i, make_pair(0, 0)));
        }
    }
    int count = -1;
    queue<int> q;
    q.push(N);
    int Q, query;
    scanf("%d", &Q);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ++count;
        for (auto it : m[t]) {
            --tmpin[it.first];
            if (tmpin[it.first] == 0) {
                q.push(it.first);
            }
        }
    }
    if (count == N) consist = false;
    if (consist) {
        printf("Impossible.\n");
        for (int i = 0; i < Q; ++i) {
            scanf("%d", &query);
            if (indge[query] == 0) {
                printf("You may take test %d directly.\n", query);
            } else printf("Error.\n");
        }
    }
    else {
        printf("Okay.\n");
        pre.resize(N, -1);
        visit.resize(N, false);
        ts.resize(N, inf);
        tv.resize(N, -1);
        for (int i = 0; i < N; ++i) {
            if (indge[i] == 0) {
                ts[i] = 0;
                tv[i] = 0;
            }
        }
        for (int i = 0; i < N; ++i) {
            int test = -1, mins = inf;
            for (int j = 0; j < N; ++j) {
                if (visit[j] == false && ts[j] < mins) {
                    test = j;
                    mins = ts[j];
                }
            }
            if (test == -1) break;
            visit[test] = true;
            for (auto it : m[test]) {
                if (visit[it.first] == false) {
                    if (ts[test] + it.second.first < ts[it.first]
                        || (ts[test] + it.second.first == ts[it.first]
                            && tv[test] + it.second.second > tv[it.first])) {
                        pre[it.first] = test;
                        ts[it.first] = ts[test] + it.second.first;
                        tv[it.first] = tv[test] + it.second.second;
                    }
                }
            }
        }
        for (int i = 0; i < Q; ++i) {
            scanf("%d", &query);
            if (pre[query] == -1) printf("You may take test %d directly.\n", query);
            else {
                num = 0;
                print(query);
                printf("\n");
            }
        }
    }
    return 0;
}
