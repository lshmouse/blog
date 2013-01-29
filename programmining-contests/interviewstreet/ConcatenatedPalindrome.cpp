// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/28/2012 16:07:14
// Description:
// Concatenated Palindrome
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 128
#define maxm 102400

int n, m;
char input[maxn][maxm];
int left[maxn][maxm], right[maxn][maxm];

char tmp[2 *maxm];
int p[2 *maxm], q[2*maxm];

void init(int k) {
    tmp[0]= '$';
    tmp[0]= '#';
    for (int i = 0; i < m ; i++){
        tmp[2*i + 2] = input[k][i];
        tmp[2*i + 3] = '#';
    }
    int mx = 0;
    int id;
    for(int i = 1; i < 2 *m + 2; i++) {
        if (mx > i)
            p[i] = min(p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for(; tmp[i+p[i]] == tmp[i-p[i]]; p[i]++) ;
        if (p[i] + i > mx ) {
            mx = p[i] + i;
            id = i;
        }
    }
    int pos = 0;
    for (int i = 0; i < 2*m + 2; i++) {
        while (pos < i + p[i]) {
            q[pos] = pos - i + 1;
            pos ++;
        }
    }
    for (int i = 0; i< m; i++){
        left[k][i] = q[2* i +2];
    }

    pos = 2*m -1;
    for (int i = 2*m -1; i >= 0; i--) {
        while (pos > i - p[i]) {
            q[pos] = i - pos + 1;
            pos --;
        }
    }
    for (int i = 0; i< m; i++){
        right[k][i] = q[2* i +2];
    }
}

int main() {
    while (scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i < n; i++){
            scanf("%s", input[i]);
            init(i);
        }
        int ret = 0;
        for (int i = 0; i < n; i++){

            ret = max(ret, left[i][0]);
            ret = max(ret, right[i][0]);

            for (int j = i + 1; j < n; j++){
                int k = 0;
                while (input[i][k] == input[j][m - 1 -k]) k++;

                ret = max(ret, 2 * k);
                if (k < m) {
                    ret = max(ret, 2 * k + left[i][k]);
                    ret = max(ret, 2 * k + right[j][m - 1 -k]);
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
