// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/24/2012 11:01:05
// Description: Requirement
//
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

#define maxn 16

bool g[maxn][maxn];
int indegree[maxn];
int dp[maxn][12];

int solve() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            queue<int> q;
    for(int i = 0; i <= n ;i ++)if (indegree[i] == 0) {
        q.push(i);
        for(int j = 1; j < 10; j++) {
            dp[i][j] = 1;
        }
    }
}

int main() {
    while (2 == scanf("%d%d", &n, &m)) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = false;
        for (int i = 0; i < n; i++) {
            g[i][n] = true;
            indegree[n]++;
        }
        for (int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            g[a][b] = true;
            indegree[b]++;
        }
    }
    return 0;
}

