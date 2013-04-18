#include <stdio.h>

#define maxn 128

int n ,m ;
int A[maxn][maxn];
bool row[maxn], col[maxn];

bool solve() {
    for (int i = 0; i < n ; i++) row[i] = true;
    for (int i = 0; i < m; i++) col[i] = true;
    
    for (int h = 100; h > 0; h --) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (A[i][j] == h){
                if (row[i] == false && col[j] == false) return false;  
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (A[i][j] == h){
                row[i] = false;
                col[j] = false;
            }
        }
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1 ; t <= T ;t ++) {
       scanf("%d%d", &n, &m);
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
       }
       printf("Case #%d: %s\n", t, solve()? "YES":"NO");
    }
}
