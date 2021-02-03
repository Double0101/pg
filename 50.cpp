#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>

using namespace std;

int main()
{
    char sentence[10010];
    char sub[10010];
    cin.getline(sentence, 10010);
    cin.getline(sub, 10010);
    int len = strlen(sentence);
    int sl = strlen(sub);
    set<char> sset;
    for (int i = 0; i < sl; ++i) {
        sset.insert(sub[i]);
    }

    for (int i = 0; i < len; ++i) {
        auto it = sset.find(sentence[i]);
        if (it != sset.end()) continue;
        printf("%c", sentence[i]);
    }
    printf("\n");
    return 0;
}
