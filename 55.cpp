#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct people {
    char name[10];
    int age, wealth;
} peo;

bool cmp(peo p1, peo p2)
{
    if (p1.wealth == p2.wealth) {
        if (p1.age == p2.age) return strcmp(p1.name, p2.name) < 0;
        return p1.age < p2.age;
    }
    return p1.wealth > p2.wealth;
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<peo> peos(N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %d", peos[i].name, &(peos[i].age), &(peos[i].wealth));
    }
    sort(peos.begin(), peos.end(), cmp);
    for (int i = 0; i < Q; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int total = 0;
        printf("Case #%d:\n", i+1);
        for (int j = 0; j < N; ++j) {
            if (peos[j].age >= b && peos[j].age <= c) {
                printf("%s %d %d\n", peos[j].name, peos[j].age, peos[j].wealth);
                ++total;
            }
            if (total == a) break;
        }
        if (total == 0) printf("None\n");
    }
    return 0;
}