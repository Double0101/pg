#include <cstdio>
#include <map>
#include <stack>

using namespace std;

typedef struct node {
    int adrs, next;
    char data;
} node;

int r1, r2, N;

map<int, int> m;
node n[100000];
stack<int> s1,s2;

void instack(int root, stack<int> &sta)
{
    int adr = root;
    while (adr != -1) {
        sta.push(adr);
        adr = n[m[adr]].next;
    }
    sta.push(-1);
}

int main()
{
    scanf("%d%d%d", &r1, &r2, &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %c %d", &(n[i].adrs), &(n[i].data), &(n[i].next));
        m[n[i].adrs] = i;
    }

    instack(r1, s1);
    instack(r2, s2);

    int start;
    while ((!s1.empty() && !s2.empty()) && s1.top() == s2.top()) {
        start = s1.top();
        s1.pop();
        s2.pop();
    }
    if (start == -1) printf("-1\n");
    else printf("%05d\n", start);
    return 0;
}