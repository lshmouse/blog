// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/19/2012 15:58:24
// Description:Lego Blocks
//
#include <stdio.h>

#define maxn 1024
#define MOD 1000000007
#define llong long long

llong A[maxn], B[maxn];
llong dp[maxn];

void init() {
    for(int i = 0; i < maxn; i++) A[i] = 0;
    A[0] = 1;
    for(int i = 0; i < maxn; i++) {
        for(int j = 1; i + j < maxn && j <= 4; j++) {
            A[i + j] = (A[i + j] + A[i]) % MOD;
        }
    }
}

llong Power(llong a, int b) {
    if (b == 0) return 1 % MOD;
    else if (b % 2 == 0) {
        llong tmp = Power(a, b/2);
        return tmp * tmp % MOD;
    } else {
        return Power(a, b - 1) * a % MOD;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    init();

    while (T-- > 0) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++) {
            B[i] = Power(A[i], n);
            dp[i] = B[i];
            for(int j = 1; j < i; j++) {
                dp[i] = ((dp[i] - B[j] * dp[i-j])%MOD + MOD) % MOD;
            }
        }
        printf("%lld\n", dp[m]);
    }
    return 0;
}

