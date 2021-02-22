#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef struct Family {
    int f;
    int minid, tmem, testate, tarea;
} Fam;
bool cmp(Fam f1, Fam f2) {
    double aa1 = f1.tarea*1.0/f1.tmem;
    double aa2 = f2.tarea*1.0/f2.tmem;
    if (aa1 == aa2) return f1.minid < f2.minid;
    return aa1 > aa2;
}
int father[10000];
int estate[10000];
int area[10000];
int index[10000];
vector<Fam> familys;
int Father(int s)
{
    if (father[s] == s) return s;
    father[s] = Father(father[s]);
    return father[s];
}
int Union(int s1, int s2)
{
    int f1 = Father(s1);
    int f2 = Father(s2);
    if (f1 != f2) {
        father[f2] = f1;
    }
}
int N;
int main()
{
    scanf("%d", &N);
    fill(father, father+10000, -1);
    fill(estate, estate+10000, 0);
    fill(area, area+10000, 0);
    int id, fa, ma, sn, son;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d%d%d", &id, &fa, &ma, &sn);
        if (father[id] == -1) father[id] = id;
        if (fa != -1) {
            if (father[fa] == -1) father[fa] = fa;
            Union(id, fa);
        }
        if (ma != -1) {
            if (father[ma] == -1) father[ma] = ma;
            Union(id, ma);
        }
        for (int j = 0; j < sn; ++j) {
            scanf("%d", &son);
            if (father[son] == -1) father[son] = son;
            Union(id, son);
        }
        scanf("%d%d", estate+id, area+id);
    }
    int famcnt = 0;
    Fam fam;
    for (int i = 0; i < 10000; ++i) {
        if (father[i] == -1) continue;
        if (Father(i) == i) {
            fam.f = i;
            fam.minid = 100000;
            fam.tarea = 0;
            fam.testate = 0;
            fam.tmem = 0;
            familys.push_back(fam);
            index[i] = famcnt++;
        }
    }
    for (int i = 0; i < 10000; ++i) {
        if (father[i] == -1) continue;
        int idx = index[Father(i)];
        familys[idx].tmem += 1;
        familys[idx].testate += estate[i];
        familys[idx].tarea += area[i];
        if (i < familys[idx].minid) familys[idx].minid = i;
    }
    sort(familys.begin(), familys.end(), cmp);
    printf("%d\n", famcnt);
    for (int i = 0; i < famcnt; ++i) {
        printf("%04d %d %.3lf %.3lf\n",
               familys[i].minid, familys[i].tmem,
               familys[i].testate*1.0/familys[i].tmem,
               familys[i].tarea*1.0/familys[i].tmem);
    }
    return 0;
}
