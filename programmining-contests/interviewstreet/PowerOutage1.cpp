#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include <algorithm>

using namespace std;

#define maxn 2000
#define maxm 2000000

struct Edge{
    int a, b,c;
};

bool cmp(const Edge& a, const Edge& b) {
    return a.c < b.c;
}

Edge A[maxm];
int n, m, k;
int f[maxn];

int father(int k) {
    if (f[k] == k) return k;
    else {
        int t = father(f[k]);
        f[k] = t;
        return t;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &A[i].a, &A[i].b, &A[i].c);
            A[i].a--;
            A[i].b--;
        }
        sort(A, A +m, cmp);

        for (int i = 0; i < n; i++) {
            f[i] = i; 
        }
        int cost = 0;
        int count = n - k;
        for (int i = 0; i < m; i++) {
            if (count <= 0) break;
            int fa = father(A[i].a);
            int fb = father(A[i].b);
            if (fa != fb) {
                cost += A[i].c;
                f[fa] = fb;
                count--;
            }
        }
        if (count <= 0) printf("%d\n", cost);
        else printf("Impossible!\n");
    }
    return 0;
}
