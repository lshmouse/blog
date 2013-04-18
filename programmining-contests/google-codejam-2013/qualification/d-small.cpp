#include <stdio.h>
#include <vector>

using namespace std;

#define maxn 41

int k, n;
int state[1<<20][maxn];
int chest[20][maxn];

bool flag[1<<20];
bool back[1<<20];
int prev[1<<20];

int keys[maxn];

void init() {
    for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < maxn; j++)
            state[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maxn; j++)
            chest[i][j] = 0;
    }
}

void solve() {
    flag[0] = true;

    for (int i = 1; i < (1<<n); i++) {
        flag[i] = false;
        for (int j = 0; j < n; j++) if (i & (1<<j)) {
            
           if (flag[i-(1<<j)] == false) continue;
           if (state[i-(1<<j)][keys[j]] == 0) continue;
        
           flag[i] = true;
           for (int k = 0; k < maxn; k++) {
               state[i][k] = state[i-(1<<j)][k] + chest[j][k]; 
           }
          
           state[i][keys[j]] --;
           break;
        }
    }
    
    back[0] = true;
    prev[0] = -1;

    for (int i = 1; i < (1<<n); i++) {
        back[i] = false;
        prev[i] = -1;
        for (int j = 0; j < n; j++) if (i & (1<<j)) {
            if (back[i-(1<<j)] == false) continue;
            if (flag[(1<<n) - 1 - i] == false) continue;

            if (state[(1<<n) - 1 - i][keys[j]] == 0) continue;
    
            back[i] = true;
            prev[i] = j;
            break;
        }
    }

    if (back[(1<<n)-1]) {
        int s = (1<<n) -1;
        int t = prev[s];
        while (t != -1 ) {
            printf(" %d", t + 1);
            s = s - (1<<t);
            t = prev[s];
        }
        
        printf("\n");
    } else {
        printf(" IMPOSSIBLE\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cases = 1 ; cases <= T ;cases ++) {
       scanf("%d%d", &k, &n);
       init();
       
       int num, t;
      
       for (int i = 0; i < k; i++) {
          scanf("%d", &t);
          state[0][t]++;
       }
       
       for (int i = 0; i < n; i++) {
          scanf("%d%d", &keys[i], &num);
          for (int j = 0; j < num; j++) {
            scanf("%d", &t);
            chest[i][t]++;
          }
       }
       printf("Case #%d:", cases);
       solve();
    }
}
