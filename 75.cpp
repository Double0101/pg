#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Examer {
    int id, tscore, rank, fn, valid;
    int scores[6];
} Eer;

int in2in[100000];
int num = 0;

int index(int id)
{
    if (in2in[id] == -1) {
        in2in[id] = num++;
    }
    return in2in[id];
}

bool cmp(Eer e1, Eer e2) {
    if (e1.tscore != e2.tscore)
        return e1.tscore > e2.tscore;
    if (e1.fn  != e2.fn)
        return e1.fn > e2.fn;
    return e1.id < e2.id;
}

int main()
{
    fill(in2in, in2in+100000, -1);
    int N, K, M;
    scanf("%d%d%d", &N, &K, &M);
    vector<Eer> exms(N);
    vector<int> psv(K+1);
    for (int i = 0; i < N; ++i) {
        exms[i].id = exms[i].tscore = exms[i].rank
                = exms[i].fn = exms[i].valid = 0;
        fill(exms[i].scores, exms[i].scores+6, -2);
    }
    for (int i = 1; i <= K; ++i) {
        scanf("%d", &(psv[i]));
    }
    int id, idx, pn, score;
    for (int i = 0; i < M; ++i) {
        scanf("%d%d%d", &id, &pn, &score);
        idx = index(id);
        exms[idx].id = id;
        if (exms[idx].scores[pn] < score) {
            int ori = exms[idx].scores[pn];
            exms[idx].scores[pn] = score;
            if (score >= 0) exms[idx].valid = 1;
            if (score == psv[pn]) ++exms[idx].fn;
            if (ori < 0) ori = 0;
            if (score < 0) score = 0;
            exms[idx].tscore += (score-ori);
        }
    }
    sort(exms.begin(), exms.end(), cmp);
    exms[0].rank = 1;
    for (int i = 1; i < N; ++i) {
        exms[i].rank = i+1;
        if (exms[i].tscore == exms[i-1].tscore) exms[i].rank = exms[i-1].rank;
    }
    for (int i = 0; i < N; ++i) {
        if (exms[i].valid == 0) continue;
        printf("%d %05d %d", exms[i].rank, exms[i].id, exms[i].tscore);
        for (int j = 1; j <= K; ++j) {
            if (exms[i].scores[j] == -2) printf(" -");
            else if (exms[i].scores[j] == -1) printf(" 0");
            else printf(" %d", exms[i].scores[j]);
        }
        printf("\n");
    }
    return 0;
}