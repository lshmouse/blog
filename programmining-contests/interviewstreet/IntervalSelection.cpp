// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/18/2012 13:33:22
// Description: Interval Selection; greedy

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define maxn 1024

struct Interval {
    int a, b;
};

Interval A[maxn];

bool cmp(const Interval& a, const Interval& b) {
    if (a.a != b.a) return a.a < b.a;
    else return a.b < b.b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &A[i].a, &A[i].b);
        }
        sort(A, A + n, cmp);
        int ret = 0;
        int right = A[0].a - 1;

        for (int i = 0; i < n; i++) {
            if (A[i].a >= right) {
                right = A[i].b;
                ret++;
            } else {
                right = A[i].b;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}

