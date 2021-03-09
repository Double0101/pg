#include <cstdio>
#include <cstring>

using namespace std;

char na[200], nb[200], sa[200], sb[200];
int N;
int main()
{
    scanf("%d %s %s", &N, na, nb);
    int la = strlen(na);
    int lb = strlen(nb);
    int da, db, va, vb, ea, eb;
    for (da = 0; da < la && na[da] != '.'; ++da);
    for (db = 0; db < lb && nb[db] != '.'; ++db);
    for (va = 0; va < la && (na[va] == '0' || na[va] == '.'); ++va);
    for (vb = 0; vb < lb && (nb[vb] == '0' || na[vb] == '.'); ++vb);
    ea = da-va, eb = db-vb;
    if (ea < 0) ++ea;
    if (eb < 0) ++eb;
    bool flag = true;
    for (int i = 0; i < la; ++i) {
        if (na[i] != '0' && na[i] != '.') flag = false;
    }
    ea = flag ? 0 : ea;
    flag = true;
    for (int i = 0; i < lb; ++i) {
        if (nb[i] != '0' && nb[i] != '.') flag = false;
    }
    eb = flag ? 0 : eb;
    flag = true;
    for (int i = 0; i < N; ++i) {
        if (va < la) {
            if (na[va] == '.') ++va;
            sa[i] = na[va++];
        } else sa[i] = '0';
        if (vb < lb) {
            if (nb[vb] == '.') ++vb;
            sb[i] = nb[vb++];
        } else sb[i] = '0';
        if (sa[i] != sb[i]) flag = false;
    }
    if (flag && ea == eb) {
        printf("YES 0.");
        for (int i = 0; i < N; ++i) {
            printf("%c", sa[i]);
        }
        printf("*10^%d\n", ea);
    }
    else {
        printf("NO 0.");
        for (int i = 0; i < N; ++i) {
            printf("%c", sa[i]);
        }
        printf("*10^%d 0.", ea);
        for (int i = 0; i < N; ++i) {
            printf("%c", sb[i]);
        }
        printf("*10^%d\n", eb);
    }
    return 0;
}
