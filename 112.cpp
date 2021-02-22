#include <cstdio>
#include <cstring>
#include <algorithm>
#define INIT -1
#define T 1
#define F 0
using namespace std;

char sentence[1010];
char result[1010];
int cnum[256];
bool isDetect[256] = {false};
int nn;

int main()
{
    scanf("%d", &nn);
    scanf("%s", sentence);
    char pre = sentence[0];
    fill(cnum, cnum+256, INIT);
    int num = 1, len = strlen(sentence);
    for (int i = 1; i <= len; ++i) {
        if (sentence[i] == pre) {
            ++num;
        } else {
            if (cnum[pre] == INIT) {
                if (num%nn == 0)
                    cnum[pre] = F;
                else cnum[pre] = T;
            } else {
                if (cnum[pre] == F && num%nn != 0) {
                    cnum[pre] = T;
                }
            }
            pre = sentence[i];
            num = 1;
        }
    }
    int j = 0;
    for (int i = 0; i <= len; ++i) {
        result[j++] = sentence[i];
        if (cnum[sentence[i]] == F) {
            i+=(nn-1);
            if (isDetect[sentence[i]] == false) {
                isDetect[sentence[i]] = true;
                printf("%c", sentence[i]);
            }
        }
    }
    printf("\n");
    printf("%s\n", result);
    return 0;
}