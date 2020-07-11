#include <cstdio>

using namespace std;

typedef struct NODE{
    int next;
    bool flag = false;
} node;

node allnode[100000];
int starta, startb, num;

int main()
{
    scanf("%d %d %d", &starta, &startb, &num);
    for (int i = 0; i < num; ++i) {
        int ad, ne;
        char c;
        scanf("%d %c %d", &ad, &c, &ne);
        allnode[ad].next = ne;
    }
    int n = starta;
    while (n != -1) {
        allnode[n].flag = true;
        n = allnode[n].next;
    }
    n = startb;
    while (n != -1) {
        if (allnode[n].flag == true) break;
        n = allnode[n].next;
    }
    if (n != -1) {
        printf("%05d\n", n);
    } else {
        printf("-1\n");
    }

    return 0;
}