//============================================================================
// Name        : interviewstreet.cpp
// Author      : Liu Shaohui(struggleliu@tencent.com)
// Version     :
// Copyright   : Your copyright notice
// Description : Queens Revised (dancing link)
//============================================================================

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#define maxn 1024

struct Node {
    int i, j;
    bool flag;
    Node* left;
    Node* right;
    Node* up;
    Node* down;
};

int n = 1000;
Node A[maxn][maxn];
Node head[maxn];
int pos[maxn];
bool column[maxn];

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

inline int abs(int a) {
    return a > 0 ? a : -a;
}

void del(int i, int j) {
    A[i][j].flag = false;
    if (A[i][j].right != NULL)
        A[i][j].right->left = A[i][j].left;
    A[i][j].left->right = A[i][j].right;

    if (A[i][j].down != NULL)
        A[i][j].down->up = A[i][j].up;

    if (A[i][j].up != NULL)
        A[i][j].up->down = A[i][j].down;
}

void resume(int i, int j) {
    //assert(!A[i][j].flag);

    A[i][j].flag = true;

    A[i][j].left->right = &A[i][j];

    if (A[i][j].right != NULL)
        A[i][j].right->left = &A[i][j];

    if (A[i][j].up != NULL)
        A[i][j].up->down = &A[i][j];

    if (A[i][j].down != NULL)
        A[i][j].down->up = &A[i][j];
}

void init() {
    for (int i = 0; i < n; i++) {
        head[i].right = &A[i][0];
        column[i] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            A[i][j].i = i;
            A[i][j].j = j;

            A[i][j].flag = true;

            A[i][j].left = (j - 1) >= 0 ? &A[i][j - 1] : NULL;
            A[i][j].right = (j + 1) < n ? &A[i][j + 1] : NULL;

            A[i][j].up = (i - 1) >= 0 ? &A[i - 1][j] : NULL;
            A[i][j].down = (i + 1) < n ? &A[i + 1][j] : NULL;
        }
    }
    for (int i = 0; i < n; i++) {
        A[i][0].left = &head[i];
    }
}

void print() {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", pos[i] + 1);
    }
    printf("\n");
}

void deleteLine(int i, int j, int dx, int dy) {
    for (int x = i, y = j; x >= 0 && x < n && y >= 0 && y < n; x += dx, y += dy) {
        if (A[x][y].flag == true) {
            del(x, y);
        }
    }
}
void releaseLine(int i, int j, int dx, int dy) {
    for (int x = i, y = j; x >= 0 && x < n && y >= 0 && y < n; x += dx, y += dy) {
        if (A[x][y].flag == false) {
            resume(x, y);
        }
    }
}

void chose(int i, int j) {
    pos[i] = j;
    column[j] = false;

    deleteLine(i, j, 1, 1);
    deleteLine(i, j, 1, -1);

    for (int k = 0; k < i; k++) {
        int dx = i - k;
        int dy = pos[i] - pos[k];
        int d = gcd(abs(dx), abs(dy));
        deleteLine(i, j, dx / d, dy / d);
    }
}

void release(int i, int j) {
    column[j] = true;

    releaseLine(i, j, 1, 1);
    releaseLine(i, j, 1, -1);

    for (int k = 0; k < i; k++) {
        int dx = i - k;
        int dy = pos[i] - pos[k];
        int d = gcd(abs(dx), abs(dy));
        releaseLine(i, j, dx / d, dy / d);
    }
}

void dfs(int depth) {
    if (depth == n) {
        print();
        exit(0);
    }
    for (Node* start = head[depth].right; start != NULL; start = start->right) {
        if (column[start->j]) {
            chose(start->i, start->j);
            dfs(depth + 1);
            release(start->i, start->j);
        }
    }
}

int main() {
    init();
    dfs(0);
    return 0;
}
