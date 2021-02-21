#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct people {
    string name;
    int height, order;
} peo;

bool cmp1(peo p1, peo p2) {
    if (p1.height == p2.height) return p1.name < p2.name;
    return p1.height > p2.height;
}
bool cmp2(peo p1, peo p2) {
    return p1.order < p2.order;
}
int main()
{
    int N, R, LL, L;
    cin >> N >> R;
    L = N/R, LL = L+N%R;
    vector<peo> peos(N);
    for (int i = 0; i < N; ++i) {
        cin >> peos[i].name >> peos[i].height;
    }
    sort(peos.begin(), peos.end(), cmp1);
    int pos = LL/2, direct = 1, step = 0;
    for (int i = 0; i < LL; ++i) {
        pos = pos+direct*step;
        peos[i].order = pos;
        ++step;
        direct = 0-direct;
    }
    for (int i = LL; i < N; i += L) {
        pos = i+L/2;
        direct = 1, step = 0;
        for (int j = 0; j < L; ++j) {
            pos = pos+direct*step;
            peos[i+j].order = pos;
            ++step;
            direct = 0-direct;
        }
    }
    sort(peos.begin(), peos.end(), cmp2);
    int i=0;
    for (i = 0; i < LL-1; ++i) {
        cout << peos[i].name << " ";
    }
    cout << peos[i].name << endl;
    for (int j = 0; j < R-1; ++j) {
        for (int k = 0; k < L-1; ++k) {
            cout << peos[LL+j*L+k].name << " ";
        }
        cout << peos[LL+j*L+L-1].name << endl;
    }
    return 0;
}