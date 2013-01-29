// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/15/2012 19:22:48
// Description: Matrix: 最大支撑树

#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>
#include <list>

using namespace std;

#define maxn 100000

struct Edge {
    int a, b, w;
};

bool cmp(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

int n, m;
int f[maxn];
Edge A[maxn];
bool flag[maxn];

int father(int i) {
    if (f[i] == i) return i;
    else {
        int fa = father(f[i]);
        f[i] = fa;
        return fa;
    }
}

void merge(int a, int b) {
    int fa = father(a);
    int fb = father(b);
    if (flag[fa]){
        f[fb] = fa;
    } else {
        f[fa] = fb;
    }
}

int main() {
    while (2 == scanf("%d%d", &n ,&m)) {
        for (int  i = 0; i < n; i++) {
            f[i] = i;
            flag[i] = false;
        }

        for(int i = 0; i < n - 1; i ++){
            scanf("%d%d%d", &A[i].a, &A[i].b, &A[i].w);
        }
        sort(A, A + n -1, cmp);
        int v;
        for(int i = 0 ; i < m; i++){
            scanf("%d", &v);
            flag[v] = true;
        }
        long long ret = 0;

        for(int i = 0; i < n -1; i++){
            int fa = father(A[i].a);
            int fb = father(A[i].b);

            if(flag[fa] && flag[fb]) {
                ret += A[i].w;
            } else {
                merge(fa, fb);
            }
        }
        printf("%lld\n", ret);
    }
    return 0;
}

