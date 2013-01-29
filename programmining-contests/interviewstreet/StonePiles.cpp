// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/22/2012 18:36:49
// Description: Stone Piles

#include <stdio.h>
#include <string.h>

#include <algorithm>

#define maxn 51

int sg[maxn];
bool flag[2 * maxn];

void dfs(int s, int sum, int current_sg) {
    if (2 * s >= sum) {
        return;
    }
    for(int i = s; i < sum - i; i++) {
        flag[current_sg ^ sg[i] ^ sg[sum - i]] = true;
        dfs(i + 1, sum - i, current_sg ^ sg[i]);
    }
}

void init() {
    sg[1] = 0; sg[2] = 0;
    for(int i = 3; i < maxn; i++) {
        for(int j = 0; j < 2 * maxn; j++) {
            flag[j] = false;
        }
        dfs(1, i, 0);
        for(int j = 0; j < 2 * maxn; j++) if (flag[j] == false) {
            sg[i] = j;
            break;
        }
        // printf("%d %d\n", i, sg[i]);
    }
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n, t;
        scanf("%d", &n);
        int ret = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &t);
            ret = ret ^ sg[t];
        }
        if (ret == 0) printf("BOB\n");
        else printf("ALICE\n");
    }
    return 0;
}
