#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; ++i) {
        vi.push_back(i);
    }

    vi.pop_back();

    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
    return 0;
}