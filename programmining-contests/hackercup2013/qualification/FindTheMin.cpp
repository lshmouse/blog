#include <stdio.h>
#include <algorithm>

using namespace std;

#define llong long long
#define maxn 204800

int n, k, r;
llong a, b, c;

int A[maxn];
int used[maxn];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &n, &k);
        scanf("%lld%lld%lld%d", &a, &b, &c, &r);
        A[0] = a;
        for (int i = 1; i < k ;i ++) {
            A[i] = (b * A[i-1] + c) % r;
        }
        for (int i = 0; i < k + 1; i++) used[i] = 0;

        for (int i = 0; i < k; i++) {
            if (A[i] < k + 1) used[A[i]]++;
        }
        int start = 0;

        for (int i = k; i < 2*k + 1; i++) {
            if (i > k && A[i - k - 1] < start && used[A[i-k-1]] == 0) {
                A[i] = A[i-k-1];
            } else {
                while (used[start] > 0) start++;
                A[i] = start;
            }
            used[A[i]] ++;
            if (A[i-k] < k + 1) {
               used[A[i-k]]--;
            }
        }
        printf("Case #%d: %d\n", t, A[k + (n - 1 - k) % (k + 1)]);
    }
    return 0;
}
