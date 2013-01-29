// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/17/2012 11:33:56
// Description: Lucky Numbers: dp
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

using namespace std;

#define llong long long

//long long dp[18 + 1][18 * 9 + 1][18 * 9 * 9 + 1];
const int MAX_LEN = 19;
const int MAX_SUM = 163;
const int MAX_SQUARE_SUM = 1783;

// 长度为i, sum 已经j， square sum 已经为 k, 种类
long long sum[MAX_LEN][MAX_SUM][MAX_SQUARE_SUM];

bool prime[MAX_SQUARE_SUM];
long long base[MAX_LEN];

void init() {
    base[0] = 1;
    for (int i =1 ;i < MAX_LEN; i++) {
        base[i] = 10 * base[i-1];
    }

    for (int i = 0; i < MAX_SQUARE_SUM; i++) {
        prime[i] = true;
    }

    prime[0] = prime[1] = false;

    for (int i = 2; i < MAX_SQUARE_SUM; i++) if (prime[i]) {
        for (int j = i; j *i < MAX_SQUARE_SUM; j++){
            prime[i*j] = false;
        }
    }

    memset(sum, 0, MAX_LEN * MAX_SUM * MAX_SQUARE_SUM * sizeof(sum[0][0][0]));

    for (int j = 0; j < MAX_SUM; j ++)
        for (int k = 0; k < MAX_SQUARE_SUM; k++) if (prime[j] && prime[k]) {
            sum[0][j][k] = 1;
        }

    for (int i = 0; i < MAX_LEN - 1; i ++) {
        for (int j = 0; j < MAX_SUM; j ++)
            for (int k = 0; k < MAX_SQUARE_SUM; k++) if (sum[i][j][k] > 0) {
                for (int l = 0; l < 10; l++) if (j >= l && k >= l*l ) {
                    sum[i + 1][ j - l][k- l *l] += sum[i][j][k];
                }
            }
    }
}

int GetDigitsNum(llong max_num) {
    int num = 0;
    while (max_num > 0) {
        num ++;
        max_num = max_num / 10;
    }
    return num;

}

llong calc(llong max_num) {
    llong ret = 0;
    int num = GetDigitsNum(max_num);

    int p_sum = 0 ;
    int p_sum_squre = 0;
    for (int i = num -1; i >= 0; i-- ) {
        int d = max_num / base[i] % 10;
        for (int j = 0; j < d; j++) {
            ret += sum[i][p_sum + j][p_sum_squre + j*j];
        }
        p_sum += d;
        p_sum_squre += d * d;
    }
    if (prime[p_sum] && prime[p_sum_squre]) ret++;

    return ret;
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    llong a, b;
    while (T-- > 0) {
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", calc(b) - calc(a - 1));
    }
    return 0;
}
