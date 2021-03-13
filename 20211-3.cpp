#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define INDEX(a) (a+10000)

using namespace std;

int idx[20001];

vector<int> heap;
int N, Q;

void buildheap(int i)
{
    int parent = i/2, son = i;
    while (parent > 0 && heap[parent] < heap[son]) {
        int tmp = heap[parent];
        heap[parent] = heap[son];
        heap[son] = tmp;
        son = parent;
        parent = son/2;
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    heap.resize(N+1);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &heap[i]);
        buildheap(i);
    }
    fill(idx, idx+20001, 0);
    for (int i = 1; i <= N; ++i) {
        idx[INDEX(heap[i])] = i;
    }
    char str[100];
    getchar();
    for (int i = 0; i < Q; ++i) {
        cin.getline(str, 100);
        int len = strlen(str);
        if (str[len-1] == 't') {
            int i;
            sscanf(str, "%d is the root", &i);
            if (i == heap[1]) printf("1");
            else printf("0");
        }
        else if (str[len-1] == 's') {
            int a, b;
            sscanf(str, "%d and %d are siblings", &a, &b);
            int ia = idx[INDEX(a)], ib = idx[INDEX(b)];
            if (ia != 0 && ib != 0 && (ia/2 == ib/2)) printf("1");
            else printf("0");
        } else {
            int a, b, p = -1, r = -1;
            for (int j = 0; j < len; ++j) {
                if (str[j] == 'p') p = j;
                if (str[j] == 'r') r = j;
            }
            if (p != -1) {
                sscanf(str, "%d is the parent of %d", &a, &b);
                int ia = idx[INDEX(a)], ib = idx[INDEX(b)];
                if (ia != 0 && ib != 0 && ia == ib/2) printf("1");
                else printf("0");
            } else {
                char dir[100];
                sscanf(str, "%d %s %d", &a, dir, &b);
                int ia = idx[INDEX(a)], ib = idx[INDEX(b)];
                if (r == -1) {
                    if (ia != 0 && ib != 0 && ia == ib*2) printf("1");
                    else printf("0");
                } else {
                    if (ia != 0 && ib != 0 && ia == ib*2+1) printf("1");
                    else printf("0");
                }
            }
        }
    }
    printf("\n");
    return 0;
}

