// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/17/2012 10:16:17
// Description:onnect the country just simulation
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define maxn 1000000

int f[64];
bool g[64][64];

int father(int i) {
    if (f[i] == i) return i;
    else {
        int fa = father(f[i]);
        f[i] = fa;
        return fa;
    }
}

int simulate(int n) {
    for (int i = 0; i < n; i ++) {
        f[i] = i;
        for (int j = 0; j < n; j++){
            g[i][j] = false;
        }
    }
    int edge = 0;
    int need = n - 1;

    while (true) {
        if (need == 0) return edge;

        int a = rand() % n;
        int b = rand() % n;
        if (a == b || g[a][b]) continue;

        edge ++;

        g[a][b] = g[b][a] = true;
        int fa = father(a);
        int fb = father(b);

        if (fa != fb) {
            f[fa] = fb;
            need --;
        }
    }
    return 0;
}

int ret[]= {0,1,2,3,4,6,7,9,10,12,14,16,18,20,22,24,26,28,30,32,34,37,39,41,44,46,48,51,53,55};

int main() {
    int n;
    while (1 == scanf("%d", &n)) {
        printf("%d\n", ret[n-1]);
    }
    /*
    for( n = 1; n <= 30; n++) {
        srand ( time(NULL) );
        int sum = 0;
        for(int i = 0; i < maxn; i ++) {
            sum += simulate(n);
        }
        printf(",%d", sum / maxn);
    } */
    return 0;
}
