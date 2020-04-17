#include <cstdio>
#include <cstdlib>
#include <vector>

std::vector<int> ans;

typedef struct node {
    int data;
    int *children = NULL;
    int size = 0;
} node;

inline
void printans()
{
    for (auto it = ans.cbegin(); it != ans.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
}

void find(node* ns, int index, int weight, int nsum)
{
    nsum += ns[index].data;
    if (nsum > weight)
        return;
    ans.push_back(ns[index].data);
    if (nsum == weight) {
        if (ns[index].size == 0)
            printans();
        ans.pop_back();
        return;
    }
    for (int i = 0; i < ns[index].size; ++i) {
        find(ns, ns[index].children[i], weight, nsum);
    }
    ans.pop_back();
}

int main()
{
    int count, parent, weight;
    scanf("%d %d %d", &count, &parent, &weight);
    node *ns = (node*) malloc(sizeof(node) * count);
    for (int i = 0; i < count; ++i) {
        scanf("%d", &(ns[i].data));
    }

    for (int j = 0; j < parent; ++j) {
        int index, num;
        scanf("%d %d", &index, &num);
        int *ch = (int*) malloc(sizeof(int) * num);
        for (int i = 0; i < num; ++i) {
            scanf("%d", &ch[i]);
        }
        ns[index].size = num;
        ns[index].children = ch;
    }
    find(ns, 0, weight, 0);

    return 0;
}