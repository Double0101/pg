#include <cstdio>
#include <map>

using namespace std;

int M, N;
map<int, int> cmap;

int main()
{
    scanf("%d %d", &M, &N);
    int cc = M*N;
    for (int i = 0; i < cc; ++i) {
        int ii;
        scanf("%d", &ii);
        if (cmap.find(ii) != cmap.end()) ++cmap[ii];
        else cmap[ii] = 1;
    }

    int cmax = 0;
    int max = -1;
    for (map<int, int>::iterator it = cmap.begin();  it != cmap.end() ; ++it) {
        if (it->second > cmax) {
            cmax = it->second;
            max = it->first;
        }
    }
    printf("%d\n", max);

    return 0;
}