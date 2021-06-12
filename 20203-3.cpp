#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct FileItem {
    int space, id;
} fi;
int N;
vector<fi> directory;
int main() {
    scanf("%d\n", &N);
    directory.resize(N);
    char in[1010];
    for (int i = 0; i < N; ++i) {
        cin.getline(in, 1010);
        int v = 0, id;
        while (in[v] == ' ') ++v;
        sscanf(in, "%d", &id);
        directory[i].space = v;
        directory[i].id = id;
    }
    vector<int> out(N);
    int Q, query;
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &query);
        int flag = -1;
        for (int j = 0; j < N; ++j) {
            out[directory[j].space] = directory[j].id;
            if (directory[j].id == query) {
                flag = directory[j].space;
                break;
            }
        }
        if (flag == -1) printf("Error: %04d is not found.\n", query);
        else {
            for (int j = 0; j <= flag; ++j) {
                if (j != 0) printf("->");
                printf("%04d", out[j]);
            }
            printf("\n");
        }
    }
    return 0;
}