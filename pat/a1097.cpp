#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct NODE {
    int next;
    int order = 2000020;
    int address;
    int data;
} NODE;

NODE allnode[100010];
bool isExist[100010] = {false};

int start, num;

bool cmp(NODE a, NODE b)
{
    return a.order < b.order;
}

int main()
{
    scanf("%d %d", &start, &num);
    for (int i = 0; i < num; ++i) {
        int adr, da, ne;
        scanf("%d %d %d", &adr, &da, &ne);
        allnode[adr].data = da;
        allnode[adr].next = ne;
        allnode[adr].address = adr;
    }

    int validc = 0, removec = 0, p = start;
    while (p != -1) {
        if (!isExist[abs(allnode[p].data)]) {
            isExist[abs(allnode[p].data)] = true;
            allnode[p].order = validc++;
        } else {
            allnode[p].order = 100010 + removec++;
        }
        p = allnode[p].next;
    }
    sort(allnode, allnode+100010, cmp);

    int count = validc+removec;
    for (int j = 0; j < count; ++j) {
        if (j != validc-1 && j != count-1) {
            printf("%05d %d %05d\n", allnode[j].address, allnode[j].data, allnode[j+1].address);
        } else {
            printf("%05d %d -1\n", allnode[j].address, allnode[j].data);
        }
    }
    return 0;
}
