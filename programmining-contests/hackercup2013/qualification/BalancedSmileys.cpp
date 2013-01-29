#include <stdio.h>
#include <string.h>

#define maxn 128
char input[maxn];
bool dp[maxn][maxn];

int main() {
    int cases;
    scanf("%d", &cases);
    gets(input);
    for (int k = 1; k <= cases; k++) {
        gets(input);
        int n = strlen(input);
        for (int i = 0; i < n; i++) {
           dp[0][i] = true;

           if (input[i] >= 'a' && input[i] <= 'z') dp[1][i] = true;
           else if (input[i] == ' ') dp[1][i] = true;
           else if (input[i] == ':') dp[1][i] = true;
           else dp[1][i] = false;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; i + j <= n; j ++) {
               dp[i][j] = false;
               // :) (:
               if (i == 2 && input[j] == ':' && input[j + i - 1] == ')') dp[i][j] = true;
               if (i == 2 && input[j] == '(' && input[j + i - 1] == ':') dp[i][j] = true;
               // (xxx)
               if (input[j] == '(' && input[i + j - 1] == ')' && dp[i - 2][j+1]) dp[i][j] = true;
               // a + b
               for (int l = 1 ; l < i; l ++) {
                   if (dp[l][j] && dp[i - l][ j + l]) dp[i][j] = true;
               }
            }
        }
        if (dp[n][0]) printf("Case #%d: Yes\n", k);
        else printf("Case #%d: NO\n", k);
    }
    return 0;
}
