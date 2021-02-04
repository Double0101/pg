#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int p, g;
    scanf("%d %d", &p, &g);
    vector<int> weight(p);
    vector<int> r(p);
    for (int i = 0; i < p; ++i) {
        scanf("%d", &(weight[i]));
    }
    queue<int> match;
    int a;
    for (int i = 0; i < p; ++i) {
        scanf("%d", &a);
        match.push(a);
    }
    while (!match.empty()) {
        int ms = match.size();
        int gn = (ms+g-1)/g;
        int rank = gn+1;
        int in = 0;
        for (int i = 0; i < gn; ++i) {
            int fat = -1, fp = -1;
            for (int j = 0; j < g && in < ms; ++j, ++in) {
                r[match.front()] = rank;
                if (weight[match.front()] > fat) {
                    fp = match.front();
                    fat = weight[match.front()];
                }
                match.pop();
            }
            match.push(fp);
        }
        if (match.size() == 1) {
            r[match.front()] = 1;
            match.pop();
            break;
        }
    }
    printf("%d", r[0]);
    for (int i = 1; i < p; ++i) {
        printf(" %d", r[i]);
    }
    printf("\n");
    return 0;
}
