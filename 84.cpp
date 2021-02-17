#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    bool isVisit[256];
    fill(isVisit, isVisit + 256, false);
    char ori[100];
    char in[100];
    scanf("%s", ori);
    scanf("%s", in);
    int len = strlen(ori);
    int a = 0;
    for (int i = 0; i < len; ++i) {
        char c = ori[i];
        if (in[a] == c) {
            if (c >= 'a' && c <= 'z') c = 'A'+(c-'a');
            isVisit[c] = true;
            ++a;
            continue;
        }
        if (c >= 'a' && c <= 'z') c = 'A'+(c-'a');
        if (isVisit[c] == false) {
            isVisit[c] = true;
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
