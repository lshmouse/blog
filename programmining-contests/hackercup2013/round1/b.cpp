#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define maxn 128

int n, m, l;
char key[] = {'a', 'b', 'c', 'd', 'e', 'f'};

char k1[maxn], k2[maxn];
int ret[maxn];

bool flag[maxn], A[maxn][maxn];

bool dfs(int k) {
    for(int i = 0 ;i < m; i++) if (A[k][i]) {
        if (flag[i] == false) {
            flag[i] = true;
            int t = ret[i];
            ret[i] = k;
            if (t == -1) return true;
            if (dfs(t)) return true;
            ret[i] = t;
        }
    }
    return false;
}

bool check(int s1,int s2){
    for(int i = 0; i < l; i++){
        if (k1[s1+i] == '?')continue;
        if (k2[s2+i] == '?')continue;
        if (k1[s1 +i] != k2[s2 +i]) return false;
    }
    return true;
}

bool match() {
   for(int i = 0; i < m ;i ++){
       for(int j = 0 ;j < m; j++) {
           A[i][j] = false;     
           if (check(i*l , j*l)){
              A[i][j] = true;     
           }
       }
   }
   for (int i = 0; i < m; i++) ret[i] = -1;
   for (int i = 0; i < m; i++) {
       for(int j = 0; j < m ;j++) flag[j] = false;
       if (!dfs(i)) return false;
   }
   return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &m);
        scanf("%s", k1);
        scanf("%s", k2);
        n = strlen(k1);
        l = n / m;
        bool res = match();
        for (int i = 0; i < n; i ++) if (k1[i] == '?'){
            bool possible = false;
            for (int j = 0; j < 6; j ++) {
                k1[i] = key[j];
                if (match()) {
                   possible = true;
                   break;
                }
            }
            if (!possible) {
                res = false; 
                break;
            }
        }
        if (!res)printf("Case #%d: IMPOSSIBLE\n", t);  
        else printf("Case #%d: %s\n", t, k1);
    }
    return 0;
}
