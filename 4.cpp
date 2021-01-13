#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct N {
	int ID;
	struct N *next;
} N;

int nnum, nlnum;
N n[100];
N plist[100];

queue<int> q;

void insert(int p, int c)
{
	n[c].next = plist[p].next;
	plist[p].next = &n[c];
}

int main() 
{
	for (int i = 0; i < 100; ++i) {
		n[i].ID = i;
		n[i].next = NULL;
	}
	for (int i = 0; i < 100; ++i) {
		plist[i].next = NULL;
	}

	scanf("%d%d", &nnum, &nlnum);
	for (int i = 0; i < nlnum; ++i) {
		int p, n, c;										// p结点编号 n节点的子节点个数
		scanf("%d%d", &p, &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &c);
			insert(p, c);
		}
	}

	q.push(1);
	int ls = 0; 											// 本层叶子结点数
	int ll = 1;												// 正在迭代的这一层的结点数
	int lln = 0;
	while (!q.empty()) {
		while (ll--) {
			int n = q.front();
			q.pop();
			if (plist[n].next == NULL) {
				++ls;
			}
			N *np = plist[n].next;
			while (np != NULL) {
				q.push(np->ID);
				++lln;
				np = np->next;
			}
			
		}
		ll = lln;
		lln = 0;
		printf("%d", ls);
		ls = 0;
		if (!q.empty()) printf(" ");
		else printf("\n");
	}

	return 0;
}

