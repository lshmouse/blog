#include <stdio.h>
#include <algorithm>

#define MOD 100000007
#define maxn 512000
#define llong long long

int n, m;
llong A[18][maxn], B[18], C[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T -- > 0) {
        scanf("%d%d", &n, &m);
        
        for (int i = 0; i < 18; i++) A[i][0] = 0;
        for (int i = 1; i <= n; i++) A[0][i] = i;

        for (int i = 1; i < 18; i++) {
            for (int j = 1; j <= n; j ++) {
               A[i][j] = (A[i][j-1] + A[i-1][j/2] ) % MOD;
            }
        }
       
        for (int i = 0; i < 18; i ++) B[i] = (A[i][n] - A[i][n/2] + MOD) % MOD;

        for (int i = 0; i <= m; i++) C[i] = 0;
        C[0] = 1;
        for (int i = 0; i <= m; i++) {
            for(int j = 0; j < 18; j++) if (i + j + 1 <= m) {
               C[i + j + 1] = (C[i + j + 1] + C[i] * B[j]% MOD) % MOD;  
            }
        }
        printf("%lld\n", C[m]);
    }
}
