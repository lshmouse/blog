// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/24/2012 09:49:09
// Description:  Liars

#include <stdio.h>
#include <iostream>

using namespace std;


#define maxn 128
#define maxm 10001

int n, m;
int factor[maxn];
int dp[maxn][maxm];

int main() {
    while (2 == scanf("%d%d", &n, &m)) {
        int a, b, c;
        int sum = 0;

        for (int i = 0; i < n; i++)
            factor[i] = 0;

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            sum +=c;
            for(int j = a - 1; j < b; j++){
                factor[j] ++;
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][sum] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= sum; j++) if (dp[i][j] >= 0) {
                dp[i+1][j] = std::max(dp[i+1][j], dp[i][j]);
                dp[i+1][j - factor[i]] = std::max(dp[i+1][j - factor[i]], dp[i][j] + 1);
            }
        }
        int ret_max = dp[n][0];

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= sum; j++) {
                dp[i][j] = n + 1;
            }
        }
        dp[0][sum] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= sum; j++) if (dp[i][j] < n) {
                dp[i+1][j] = std::min(dp[i+1][j], dp[i][j]);
                dp[i+1][j - factor[i]] = std::min(dp[i+1][j - factor[i]], dp[i][j] + 1);
            }
        }
        int ret_min = dp[n][0];
        printf("%d %d\n", ret_min, ret_max);
    }
}
