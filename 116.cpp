#include <cstdio>
#include <algorithm>

using namespace std;

bool isPrime[10000];
bool isCheck[10000];
int rak[10000];

void initTable()
{
    fill(isPrime, isPrime+10000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 100; ++i) {
        if (isPrime[i] == true) {
            for (int j = i*i; j < 10000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    initTable();
    fill(isCheck, isCheck+10000, false);
    fill(rak, rak+10000, -1);
    int N, id;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &id);
        rak[id] = i;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (isCheck[id] == true) {
            printf("Checked\n");
            continue;
        }
        int r = rak[id];
        if (r == -1) printf("Are you kidding?\n");
        else {
            if (isPrime[r] == true)
                printf("Minion\n");
            else if (r == 1)
                printf("Mystery Award\n");
            else printf("Chocolate\n");
            isCheck[id] = true;
        }
    }
    return 0;
}
