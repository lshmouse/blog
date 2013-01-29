#include <stdio.h>
#include <string.h>

#define maxn 15
int n, A[maxn];

int dp[1<<maxn];

bool ordered(int s) {
    int pre_index = -1;
    for(int i = 0; i < n; i++) if ((s &(1<<i)) > 0) {
        if (pre_index != -1) {
            if (A[i] <= A[pre_index]) return false;
        }
        pre_index = i;
    }
    return true;
}

bool AliceChoose(int s) {
    int count = 0;
    for(int i = 0; i < n; i++)if ((s&(1<<i)) > 0) count++;
    if ((n - count)%2 ==0) return true;
    else return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- >0) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }

        // 0: alice, 1:Bob
        for(int i = 1; i < (1<<n); i++) {
            if (ordered(i)) {
                if (AliceChoose(i)) {
                    dp[i] = 1;
                } else {
                    dp[i] = 0;
                }
            } else {
                int a = 0, b = 0;
               
                for(int j = 0 ; j < n; j++) if ((i & (1<<j)) > 0) {
                    if (dp[i - (1<<j)] == 0) a++;
                    else b++;
                }

                if (AliceChoose(i)) {
                    if (a > 0) dp[i] = 0;
                    else dp[i] = 1;
                } else {
                    if (b > 0) dp[i] = 1;
                    else dp[i] = 0;
                }
            }
        }
        
        if (dp[(1<<n) -1] == 0) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
