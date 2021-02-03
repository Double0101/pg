#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct node {
    int address, key, next;
} node;
int address[200010];
bool in[200010];
node ns[100000];

int main()
{
    fill(address, address+200010, -1);
    fill(in, in+200010, false);
    int N, start;
    scanf("%d %d", &N, &start);
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int ki = b+100000;
        address[ki] = a;
        ns[a].address = a;
        ns[a].key = b;
        ns[a].next = c;
    }
    int index = start;
    int total = 0;
    while (index != -1) {
        in[ns[index].key+100000] = true;
        index = ns[index].next;
        ++total;
    }
    if (total == 0) {
        printf("0 -1\n");
        return 0;
    }
    index = 0;
    while (in[index] != 1) ++index;
    printf("%d %05d\n", total, address[index]);
    for (int i = 0; i < total-1; ++i) {
        printf("%05d %d", address[index], ns[address[index]].key);
        ++index;
        while (in[index] != 1) ++index;
        printf(" %05d\n", address[index]);
    }
    printf("%05d %d -1\n", address[index], ns[address[index]].key);
    return 0;
}
