#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char sens[105][260];
int slen[105];

int main()
{
    int N, min = 270;
    scanf("%d\n", &N);
    for (int i = 0; i < N; ++i) {
        cin.getline(sens[i], 260);
        slen[i] = strlen(sens[i]);
        if (slen[i] < min) min = slen[i];
    }
    int i, flag;
    for (i = 1; i <= min; ++i) {
        char c = sens[0][slen[0]-i];
        flag = 0;
        for (int j = 1; j < N; ++j) {
            if (sens[j][slen[j]-i] == c) continue;
            flag = 1;
            break;
        }
        if (flag == 1) break;
    }
    if (i == 1) printf("nai\n");
    else {
        printf("%s\n", sens[0]+slen[0]-i+1);
    }
    return 0;
}
