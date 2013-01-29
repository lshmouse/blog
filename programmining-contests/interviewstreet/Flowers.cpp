// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/17/2012 11:08:32
// Description:  Flowers: greedy
//
#include <stdio.h>

#include <iostream>
#include <algorithm>
using namespace std;

int A[128];

int main() {
    int n, m;
    while (2 == scanf("%d%d", &n, &m)) {
        for (int i = 0 ; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, A + n);
        reverse(A,  A + n);
        long long sum = 0;
        for(int i = 0; i < n ; i ++) {
            int multi = (i + m) / m;
            sum += multi*A[i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}

