#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a1, a2, b1, b2, c1, c2;
    scanf("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
    a1 += a2;
    b1 += b2;
    c1 += c2;
    int carry;
    carry = c1/29;
    c1 = c1%29;
    b1 += carry;
    carry = b1/17;
    b1 = b1%17;
    a1 += carry;
    printf("%d.%d.%d\n", a1, b1, c1);
    return 0;
}