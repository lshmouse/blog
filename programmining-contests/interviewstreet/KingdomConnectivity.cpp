// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/16/2012 15:20:32
// Description: Kingdom Connectivity

#include <stdio.h>

#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

#define maxn 10240
#define MOD 1000000000

int n, m;
vector<list<int> > edges;
bool flag[maxn];
int indgree[maxn];
int path[maxn];

void bfs() {
    queue<int> q;
    q.push(0);
    flag[0] = true;

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        list<int>::iterator itr = edges[s].begin();
        for (; itr != edges[s].end(); itr++) {
            int t = *itr;
            if (flag[t] == false) {
                q.push(t);
                flag[t] = true;
            }
        }
    }
}

int top_sort() {
    queue<int> q;

    for(int i = 0; i < n; i++) path[i] = 0;
    path[0] = 1;

    for(int i = 0; i < n; i++) if (flag[i] && indgree[i] == 0) q.push(i);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        list<int>::iterator itr = edges[s].begin();
        for (; itr != edges[s].end(); itr++) {
            int t = *itr;
            if (flag[t]) {
                path[t] = (path[t] + path[s]) % MOD;
                --indgree[t];
                if (indgree[t] == 0) {
                    q.push(t);
                }
            }
        }
    }
    // circle
    if (path[n-1] == 0) return -1;
    else return path[n-1];
}

int main() {
    while (2 == scanf("%d%d", &n, &m)) {
        int a, b;
        edges.clear();
        edges.resize(n);

        for (int i = 0; i < n; i++){
            indgree[i] = 0;
            flag[i] = false;
        }

        for(int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            a--; b--;
            edges[a].push_back(b);
        }
        bfs();

        if (flag[n-1] == false) {
            printf("0\n");
        } else {
            for (int i = 0; i < n; i++) if (flag[i]) {
                list<int>::iterator itr = edges[i].begin();
                for (; itr != edges[i].end(); itr++) {
                    int t = *itr;
                    if (flag[t]) indgree[t]++;
                }
            }
            int ret = top_sort();
            if (ret == -1) {
                printf("INFINITE PATHS\n");
            } else {
                printf("%d\n", ret);
            }
        }
    }
    return 0;
}
