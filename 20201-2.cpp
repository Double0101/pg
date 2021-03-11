#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool m[100005];
vector<int> ss;
vector<vector<int>> bid;
bool out[10];
int main()
{
    fill(m, m+100005, false);
    fill(out, out+11, false);
    int a, b, N, M;
    scanf("%d%d", &a, &b);
    m[a] = m[b] = true;
    ss.push_back(a);
    ss.push_back(b);
    scanf("%d%d", &N, &M);
    bid.resize(N);
    for (int i = 0; i < N; ++i) {
        bid[i].resize(M);
        for (int j = 0; j < M; ++j) {
            scanf("%d", &(bid[i][j]));
        }
    }
    int rest = N;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (out[j]) continue;
            int ans = bid[j][i];
            if (m[ans] == true) {
                printf("Round #%d: %d is out.\n", i+1, j+1);
                out[j] = true;
                --rest;
                continue;
            }
            bool flag = false;
            for (int k = 0; k < ss.size(); ++k) {
                int la = ss[k]-ans;
                if ((la > 0 && m[la])) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                printf("Round #%d: %d is out.\n", i+1, j+1);
                out[j] = true;
                --rest;
                continue;
            }
            ss.push_back(ans);
            m[ans] = true;
        }
    }
    if (rest > 0) {
        printf("Winner(s):");
        for (int i = 0; i < N; ++i) {
            if (out[i] == false) printf(" %d", i+1);
        }
        printf("\n");
    } else {
        printf("No winner.\n");
    }
    return 0;
}