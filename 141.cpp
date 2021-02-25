#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct School {
    string name;
    int scoreA, scoreB, scoreT, score;
    int count, rank;
    School(string n): name(n) {
        scoreA = scoreB = scoreT = 0;
        count = rank = 0;
    }
} scl;
bool cmp(scl s1, scl s2)
{
    if (s1.score == s2.score) {
        if (s1.count == s2.count) return s1.name < s2.name;
        return s1.count < s2.count;
    }
    return s1.score > s2.score;
}

unordered_map<string, int> schl;

int num = 0;
vector<scl> ss;

int main()
{
    int N;
    scanf("%d", &N);
    char level, school[10], id[10];
    int score;
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %s", id, &score, school);
        int j = 0;
        level = id[0];
        while (school[j] != '\0') {
            if (school[j] >= 'A' && school[j] <= 'Z')
                school[j] += ('a'-'A');
            ++j;
        }
        if (schl.find(school) == schl.end()) {
            schl[school] = num++;
            ss.emplace_back(school);
        }
        int idx = schl[school];
        ++ss[idx].count;
        if (level == 'A') ss[idx].scoreA += score;
        else if (level == 'B') ss[idx].scoreB += score;
        else ss[idx].scoreT += score;
    }
    for (int i = 0; i < num; ++i) {
        ss[i].score = (int)(ss[i].scoreA*1.0 + ss[i].scoreB*1.0/1.5 + ss[i].scoreT*1.5);
    }
    sort(ss.begin(), ss.end(), cmp);
    ss[0].rank = 1;
    for (int i = 1; i < num; ++i) {
        if (ss[i].score == ss[i-1].score) ss[i].rank = ss[i-1].rank;
        else ss[i].rank = i+1;
    }
    printf("%d\n", num);
    for (int i = 0; i < num; ++i) {
        printf("%d %s %d %d\n", ss[i].rank, ss[i].name.c_str(), ss[i].score, ss[i].count);
    }
    return 0;
}
