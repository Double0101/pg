#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

typedef struct Student {
    string id;
    int point, mid, final, score;
} stu;

unordered_map<string, int> n2i;
vector<stu> stus(30000);
int num = 0;

bool cmp(stu s1, stu s2)
{
    if (s1.score == s2.score) return s1.id < s2.id;
    return s1.score > s2.score;
}

int stuidx(string name)
{
    auto it = n2i.find(name);
    if (it == n2i.end()) {
        stus[num].id = name;
        stus[num].final = stus[num].mid = stus[num].point = stus[num].score = -1;
        n2i[name] = num;
        return num++;
    }
    return it->second;
}
int P, M, N;

int main()
{
    scanf("%d%d%d", &P, &M, &N);
    int index, score;
    char id[21];
    for (int i = 0; i < P; ++i) {
        scanf("%s %d", id, &score);
        if (score < 200) continue;
        index = stuidx(id);
        stus[index].point = score;
    }
    for (int i = 0; i < M; ++i) {
        scanf("%s %d", id, &score);
        if (n2i.find(id) == n2i.end()) continue;
        index = stuidx(id);
        stus[index].mid = score;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%s %d", id, &score);
        if (n2i.find(id) == n2i.end()) continue;
        index = stuidx(id);
        stus[index].final = stus[index].score = score;
        if (stus[index].mid > stus[index].final) {
            stus[index].score = int(stus[index].mid*0.4+stus[index].final*0.6+0.5);
        }
    }
    vector<stu> result;
    for (int i = 0; i < num; ++i) {
        if (stus[i].score >= 60) result.push_back(stus[i]);
    }
    sort(result.begin(), result.end(), cmp);
    for (int i = 0; i < result.size(); ++i) {
        printf("%s %d %d %d %d\n", result[i].id.c_str(),
               result[i].point, result[i].mid, result[i].final, result[i].score);
    }
    return 0;
}