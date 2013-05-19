#include <stdio.h>
#include <string.h>
#include <math.h>

#include <vector>
#include <algorithm>

using namespace std;
#define llong long long

#define maxn 1024000
int n, m, A[maxn];

int solve() {
    sort(A, A +n);
    int cnt = 0;
    int ans = n;
    llong sum = m;
    for (int i = 0; i < n; i++) {
        ans = min(ans, cnt + (n - i));
        if (sum == 1 && sum <= A[i]) {
            return ans;
        }
        while (sum <= A[i]) {
            cnt +=1;
            sum += sum -1;
        }
        sum +=A[i];
    }
    ans = min(ans, cnt);
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <=T; k++) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; i ++) scanf("%d", &A[i]);
        printf("Case #%d: %d\n", k, solve());
    }
    return 0;
}
