#include <stdio.h>
#include <string.h>

#include <iostream>
#include <algorithm>

#define maxn 310
#define MOD 1000000007
#define llong long long


int n, m;
int A[10], B[10];
llong C[maxn][maxn];

llong dp[11][maxn];
llong step[11][maxn][101];
llong sum[11][maxn];

void init() {
    for(int i = 0; i < maxn; i++) {
        C[i][0] = C[i][i] = 1;
    }
    for(int i = 2; i < maxn; i++) {
        for(int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])% MOD;
        }
    }
}

void CalcSteps() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < B[i]; k++) {
                step[i][j][k] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        step[i][0][A[i] -1] = 1;
       
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < B[i]; k++) if (step[i][j-1][k] > 0) {
                if (k + 1 < B[i]) 
                    step[i][j][k + 1] = (step[i][j][k + 1] + step[i][j-1][k]) % MOD;
                if (k - 1 >= 0)
                    step[i][j][k - 1] = (step[i][j][k - 1] + step[i][j-1][k]) % MOD;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= m; j++) {
            sum[i][j] = 0;
            for(int k = 0; k < B[i]; k++) {
                sum[i][j] = (sum[i][j] + step[i][j][k]) % MOD;
            }
        }
    }
}

int main() {
    int T;
    init();

    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d%d", &n, &m);
    
        for (int i = 0; i < n; i++){
            scanf("%d", &A[i]);            
        }
        for (int i = 0; i < n; i++){
            scanf("%d", &B[i]);            
        }
        
        CalcSteps();

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j] = 0;
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) if (dp[i][j] > 0){
                for(int k = 0; k <= m -j; k++){
                    dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j] * sum[i][k] % MOD * C[j+k][k] % MOD) % MOD;
                }
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}
