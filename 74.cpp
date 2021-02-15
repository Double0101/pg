#include <cstdio>
#include <vector>

using namespace std;

int data[100010], netadr[100010], list[100010], result[100010];
int fadr, nc, rc, sum = 0;

int main()
{
    scanf("%d %d %d", &fadr, &nc, &rc);
    for (int i = 0; i < nc; ++i) {
        int adr;
        scanf("%d", &adr);
        scanf("%d %d", data+adr, netadr+adr);
    }
    int nxt = fadr;
    while (nxt != -1) {
        list[sum++] = nxt;
        nxt = netadr[nxt];
    }
    for (int i = 0; i < sum; ++i) {
        result[i] = list[i];
    }
    for (int i = 0; i < (sum - (sum % rc)); ++i) {
        result[i] = list[i/rc*rc+rc-1-i%rc];
    }
    for (int i = 0; i < sum-1; ++i) {
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i+1]);
    }
    printf("%05d %d -1\n", result[sum-1], data[result[sum-1]]);

    return 0;
}
