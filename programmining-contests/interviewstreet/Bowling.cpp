#include <stdio.h>

#define maxn 128
#define maxm 30 * maxn
#define MOD 1000000007

int dp[maxn][maxm][8];

int calc_value(int state, int x, int y) {
    int sum = 0;
    if ((state / 4) == 1) { // 前一个为满分
        sum += x;
    }
    if ((state%2) == 1) {  // 前一个是10
        sum += (x + y);
    }
    if ((state /2 % 2) == 1) { // 前第二个为10
        sum += x;
    }
    return sum;
}

int calc_state(int state, int x, int y) {
    if (x < 10 && x + y < 10) return 0;
    if (x < 10 && x + y == 10) return 4;
    
    if (x == 10) {
        state = (state % 2) * 2 + 1;
        return state;
    }
    return -1;
}

void init() {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxm; j++) {
            for (int k = 0; k < 8; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i < 101; i ++) {
        for (int j = 0; j <= 30 *(i-1); j++) {
            for (int k = 0; k < 8; k++) if (dp[i - 1][j][k] > 0){
                for (int x = 0 ; x <= 10; x++) {
                    for (int y = 0; x + y <= 10; y++) {
                        int jj = j + calc_value(k, x, y) + x + y;
                        int state = calc_state(k , x, y);  
                        dp[i][jj][state] = (dp[i][jj][state] + dp[i - 1][j][k]) % MOD;
                    }
                }
            }
        }
    }
    for (int i = 1; i < 101; i ++) {
        for (int j = 0; j <= 30 *i; j++) {
            for (int k = 0; k < 8; k++) if (dp[i][j][k] > 0){
               if ((k % 2) == 1) { // two ball 
    
                    for (int x = 0 ; x <= 10; x++) {
                        for (int y = 0; y <= 10; y++) {
                            if (x < 10 && (x + y) > 10) continue;

                            int add  = j + calc_value(k, x, y);

                            dp[i][add][0] = (dp[i][add][0] + dp[i][j][k]) % MOD; 
                        }
                    }
                } else if ((k / 4) == 1){ // only one ball
                    for (int x = 0 ; x <= 10; x++) {
                        int add  = j + x;
                        dp[i][add][0] = (dp[i][add][0] + dp[i][j][k] ) % MOD; 
                    }
                }
            }
        }
    }
}

int main() {
    init();
    int T;
    scanf ("%d", &T);
    while (T-- > 0) {
        int n, m;
        scanf("%d%d", &n, &m);
        printf("%d\n", dp[n][m][0]);
    }
}
