#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Request {
    int in, out;
} req;

bool cmp(req r1, req r2) { return r1.in == r2.in ? r1.out < r2.out : r1.in < r2.in; }

vector<req> reqs;
int N, mx = 0;

int main() {
    scanf("%d", &N);
    reqs.resize(N);
    int a, b, c;
    for (int i = 0; i < N; ++i) {
        scanf("%d:%d:%d", &a, &b, &c);
        reqs[i].in = a*3600 + b*60 + c;
        scanf("%d:%d:%d", &a, &b, &c);
        reqs[i].out = a*3600 + b*60 + c;
    }
    sort(reqs.begin(), reqs.end(), cmp);
    int out = 0;
    for (int i = 0; i < N; ++i) {
        if (reqs[i].in < out) continue;
        int o = reqs[i].out, has = -1;
        for (int j = i+1; j < N; ++j) {
            if (reqs[j].out < o) {
                has = j;
                break;
            }
        }
        if (has == -1) {
            ++mx;
            out = o;
        }
        else {
            i = has-1;
        }
    }
    printf("%d\n", mx);
    return 0;
}
