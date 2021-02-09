#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int inrange(char c) {
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'a' && c <= 'z') return 2;
    if (c >= 'A' && c <= 'Z') return 3;
    return 0;
}

int main()
{
    map<string, int> mm;
    int dif = 'a' - 'A';
    char sentence[1048580];
    int start, end = 0, max = -1;
    string mstr;
    cin.getline(sentence, 1048580);
    while (sentence[end] != '\0') {
        start = end;
        int t = inrange(sentence[end]);
        while (t > 0) {
            if (t == 3) {
                sentence[end] += dif;
            }
            t = inrange(sentence[++end]);
        }
        string s(sentence+start, sentence+end);
        if (mm.find(s) == mm.end()) mm[s] = 0;
        ++mm[s];
        if (mm[s] > max) {
            max = mm[s];
            mstr = s;
        }
        while (sentence[end] != '\0' && inrange(sentence[end]) == 0) ++end;
    }
    printf("%s %d\n", mstr.c_str(), mm[mstr]);
    return 0;
}
