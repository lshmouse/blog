#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;
#define MOD 1000000007
#define maxn 10240
#define llong long long

int C[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; i++) C[i][0] = C[i][i] = 1;
    for (int i = 2; i < maxn; i++) {
        for(int j = 1; j < i; j ++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}

int n, k, A[maxn];

int main() {
    int T;
    scanf("%d", &T);
    init();
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, A + n);
        llong ret = 0;
        for (int i = k - 1; i < n; i++){
            ret = (ret + 1LL * A[i] * C[i + 1 - 1][k - 1]) % MOD;
        }
        printf("Case #%d: %lld\n", t, ret);
    }
    return 0;
}
