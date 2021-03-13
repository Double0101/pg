#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, maxp;
bool prime[100000];

void init() {
    fill(prime, prime+maxp+1, true);
    prime[0] = prime[1] = false;
    int end = sqrt(maxp)+1;
    for (int i = 2; i <= end; ++i) {
        if (!prime[i]) continue;
        for (int j = i*i; j <= maxp; j+=i) {
            prime[j] = false;
        }
    }
}
int flag = 0, f, d = -1;
vector<int> pl;
int main() {
    scanf("%d%d", &N, &maxp);
    init();
    for (int i = 2; i <= maxp; ++i) {
        if (prime[i]) {
            pl.push_back(i);
        }
    }
    if (pl.size() < N) printf("%d\n", pl[pl.size()-1]);
    else {
        for (int i = 0; i < pl.size(); ++i) {
            for (int j = i+1; j < pl.size(); ++j) {
                int first = pl[i], second = pl[j];
                int diff = second - first, cot = 1;
                while (second <= maxp && prime[second]) {
                    ++cot;
                    second+=diff;
                    if (cot == N) break;
                }
                if (cot == N && diff >= d) {
                    flag = 1;
                    f = first;
                    d = diff;
                }
            }
        }
        if (flag == 0) printf("%d\n", pl[pl.size()-1]);
        else {
            for (int i = 0; i < N; ++i) {
                if (i != 0) printf(" ");
                printf("%d", f+i*d);
            }
            printf("\n");
        }
    }
    return 0;
}
