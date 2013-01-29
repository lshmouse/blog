// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/18/2012 13:46:49
// Description: circle Summation: matrix multiplication
//
#include <stdio.h>
#include <iostream>

#include <algorithm>

using namespace std;

#define maxn 64
#define MOD 1000000007

int n, m;
int input[maxn], output[maxn];
int A[maxn][maxn];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

}
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        A[i][i] = 1;
        for(int j = i; j < n ; j ++) {
            A[i][(n + j - 1)%n] += A[i][j];
            A[i][(n + j + 1)%n] += A[i][j];
        }
    }
    power(m / n);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }
        init();
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) output[j] = 0;

            for(int j = 0; j < n; j++)
                for(int k = 0; k < n ;k++) {
                    output[i
                }
            }
        }
    }
    return 0;
}
