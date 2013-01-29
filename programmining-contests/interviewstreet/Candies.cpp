// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/15/2012 18:51:10
// Description: Candies
//
#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 102400

int n, A[maxn], B[maxn];

int decrease(int s) {
    int ret = 0;
    while ((s + ret + 1) < n && A[s + ret + 1] < A[s + ret]) {
        ret++;
    }
    return ret;
}

int main() {
    while (1 == scanf("%d", &n)) {
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }
        int start = 1;

        for(int i = 0; i < n; i++){
            if (i == 0 || A[i] == A[i-1]){
                start = 1;
            } else {
                start = B[i-1] + 1;
            }

            int d = decrease(i);

            if(d > 0) {
                B[i] = max(start, d + 1);
                for(int k = 0; k < d; k++){
                    B[i + 1 + k] = d - k;
                }
                i+=d;
            } else {
                B[i] = start;
            }
        }

        long long ret = 0;

        for(int i = 0; i < n; i++){
            ret += B[i];
        }
        printf("%lld\n", ret);
    }
    return 0;
}

