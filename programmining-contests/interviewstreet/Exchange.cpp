#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define maxn 128

int n, A[maxn];
char g[maxn][maxn];
bool flag[maxn];

vector<int> pos, values;

void dfs(int s) {
    if (flag[s] == true) return;
    flag[s] = true;

    pos.push_back(s);
    values.push_back(A[s]);

    for (int i = 0; i < n; i++) if (g[s][i] == 'Y') {
        dfs(i);      
    }
}

int main () {
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", g[i]);
        }
        for (int i = 0; i < n; i++) flag[i] = false;
        
        for (int i = 0; i < n; i++) {
            if (flag[i] == false) {
                dfs(i);
            }
            sort(pos.begin(), pos.end());
            sort(values.begin(), values.end());
    
            for (int i = 0; i < pos.size(); i++) {
                A[pos[i]] = values[i]; 
            }
            pos.clear();
            values.clear();

        }
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    } 
}
