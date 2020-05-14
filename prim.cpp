#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//typedef struct Node {
//    int name;
//    vector<Node*> *children;
//} Node;

bool *visited;
int **W;
int citynum, roadnum;
int *mindis;

//Node* newnode(int city)
//{
//    Node *n = (Node*) malloc(sizeof(Node));
//    n->name = city;
//    n->children = new vector<Node*>;
//    return n;
//}
//
//Node* release(Node* n) {
//    if (n == NULL) return NULL;
//    delete(n->children);
//    free(n);
//    return NULL;
//}

int prim()
{
    mindis[0] = 0;
    int ans = 0;
    for (int i = 0; i < citynum; ++i) {
        int min = INT_MAX, next = -1;
        for (int j = 0; j < citynum; ++j) {
            if (!visited[j] && mindis[j] < min) {
                min = mindis[j];
                next = j;
            }
        }

        if (next == -1) return -1;
        ans += min;
        visited[next] = true;
        for (int k = 0; k < citynum; ++k) {
            if (!visited[k] && mindis[k] > W[next][k]) {
                mindis[k] = W[next][k];
            }
        }
    }

    return ans;
}

int main()
{
    cin >> citynum >> roadnum;
    W = (int**) malloc(sizeof(int*) * citynum);
    for (int i = 0; i < citynum; ++i) {
        W[i] = (int*) malloc(sizeof(int) * citynum);
        int *w = W[i];
        fill(w, w + citynum, INT_MAX);
        w[i] = 0;
    }
    visited = (bool*) malloc(sizeof(bool) * citynum);
    fill(visited, visited + citynum, false);
    mindis = (int*) malloc(sizeof(int) * citynum);
    fill(mindis, mindis + citynum, INT_MAX);
    for (int j = 0; j < roadnum; ++j) {
        int c1, c2, len;
        cin >> c1 >> c2 >> len;
        W[c1][c2] = len;
        W[c2][c1] = len;
    }

//    Node *root = newnode(0);
    cout << prim() << endl;
    return 0;
}