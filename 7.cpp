#include <cstdio>
#include <cstdlib>

int arr[10000];
int dp[10010];
int K;

/*
 * 分治
 */

//typedef struct SUB{
//    int start, end;
//    int sum;
//} SUB;
//
//SUB findCrossMax(int start, int mid, int end)
//{
//    SUB s;
//    int sum = arr[mid], ps=mid;
//    int max = sum;
//    for (int i = mid-1; i >= start ; --i) {
//        sum+=arr[i];
//        if (sum > max) {
//            max = sum;
//            ps = i;
//        }
//    }
//    s.start = ps;
//    s.sum = max;
//    sum = 0, ps = mid;
//    max = sum;
//    for (int i = mid+1; i <= end; ++i) {
//        sum+=arr[i];
//        if (sum > max) {
//            max = sum;
//            ps = i;
//        }
//    }
//    s.end = ps;
//    s.sum += max;
//    return s;
//}
//
//SUB findMaxSub(int start, int end)
//{
//    int mid = (start+end)/2;
//    SUB sc = findCrossMax(start, mid, end);
//    if (mid == end) return sc;
//    SUB s1 = findMaxSub(start, mid);
//    SUB s2 = findMaxSub(mid+1, end);
//    if (sc.sum > s1.sum && sc.sum > s2.sum) return sc;
//    if (s1.sum > s2.sum && s1.sum > sc.sum) return s1;
//    if (s2.sum > s1.sum && s2.sum > sc.sum) return s2;
//    return s1;
//}

int main()
{
    scanf("%d", &K);
    int *a, *b;
    int t = 1;
    for (a = arr, b = arr+K; a != b; ++a) {
        scanf("%d", a);
        if (t && *a >= 0) t=0;
    }
    if (t) {
        printf("%d %d %d\n", 0, arr[0], arr[K-1]);
        return 0;
    }

    int start = 0;
    int sum = 0, ss = 0, se = 0;
    dp[0] = 0;
    for (int i = 0; i < K; ++i) {
        if (dp[i] < 0) {
            dp[i+1] = arr[i];
            start = i;
        }
        else dp[i+1] = dp[i] + arr[i];
        if (dp[i+1] > sum) {
            sum = dp[i+1];
            se = i+1;
            ss = start;
        }
    }

//    SUB s = findMaxSub(0, K-1);
//    printf("%d %d %d\n", s.sum, arr[s.start], arr[s.end]);
    if (se==0) {
        printf("0 0 0\n");
        return 0;
    }
    printf("%d %d %d\n", sum, arr[ss], arr[se-1]);
    return 0;
}