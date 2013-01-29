// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/24/2012 09:31:04
// Description: Ants

#include <stdio.h>
#include <algorithm>

using namespace std;

#define llong long long
#define maxn 128

int n;
int A[maxn];
int f[maxn], C[maxn];

int father(int a) {
    if (f[a] == a) return a;
    else {
        int fa = father(f[a]);
        f[a] = fa;
        return fa;
    }
}

void merge(int a, int b) {
    int fa = father(a);
    int fb = father(b);
    f[fa] = fb;
    C[fb] += C[fa];
}

int main() {
    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, A + n);
        llong ret = 100000L * (n/2) * (n - n/2) * 4;
        for (int i = 0;i < n; i++) {
            f[i] = i;
            C[i] = 1;
        }

        for (int i = 0;i < n; i++){
            if (A[(i + 1) % n] - A[i] == 1) {
                merge(i, (i + 1) % n);
            }
        }
        for (int i = 0;i < n; i++) if (f[i] == i) {
            ret += C[i] / 2 * 2;
        }
        printf("%lld\n", ret);
    }
    return 0;
}
