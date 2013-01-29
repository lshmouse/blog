// Copyright (C) 2012 - Tencent Inc.
// Author: Liu Shaohui (struggleliu@tencent.com)
//
// Created: 10/16/2012 09:52:38
// Description: Zombie March : sparse matrix multiplication but just need a few
// steps, the answer will be stable
//

#include <stdio.h>
#include <math.h>

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

#define maxn 102400
struct Edge{
    int a, b;
};

int n, m, k;
double A[2][maxn], top[2][5];
int degree[maxn];

vector<Edge> edges;

void getTop5(double* data, double* top) {
    priority_queue<double, vector<double>, greater<double> > heap;
    for(int i = 0; i < n; i++){
        heap.push(data[i]);
        if (heap.size() > 5) {
            heap.pop();
        }
    }
    for(int i = 0; i < 5; i++) {
        top[4-i] = heap.top();
        heap.pop();
    }
}

void translate(int step) {
    for(int i = 0; i < n ; i++) A[(step+1) % 2][i] = 0.0;

    for(int i = 0; i < edges.size(); i++) {
        A[(step + 1) % 2][edges[i].a] += A[step%2][edges[i].b] / degree[edges[i].b];
        A[(step + 1) % 2][edges[i].b] += A[step%2][edges[i].a] / degree[edges[i].a];
    }
}

bool stable() {
    for(int i = 0; i < 5; i++){
        if (fabs(top[0][i] - top[1][i]) > 1e-3) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d%d%d", &n, &m, &k);
        edges.clear();
        Edge tmp;

        for (int i = 0; i < n; i++)
            degree[i] = 0;

        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &tmp.a, &tmp.b);
            edges.push_back(tmp);
            degree[tmp.a]++;
            degree[tmp.b]++;
        }

        for(int i = 0; i < n; ++i){
            scanf("%lf", &A[0][i]);
        }

        getTop5(A[0], top[0]);

        for(int i = 0; i < k; i++){
            translate(i);
            getTop5(A[(i+1)%2], top[(i+1)%2]);
            if(stable()) {
                break;
            }
        }

        for(int i = 0; i < 5; i++) {
            printf("%d ", int(top[0][i] + 0.5));
        }

        printf("\n");
    }
    return 0;
}
