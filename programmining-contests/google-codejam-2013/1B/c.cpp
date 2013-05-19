#include <stdio.h>
#include <string.h>
#include <math.h>

#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

#define llong long long
#define maxn 5120

char str[maxn], buffer[32];
int n, A[maxn][6];
set<string> dict;


void dfsDict(int i, int len, int dist) {
    if (i == len) {
       string key(buffer, len);
       dict.insert(key);
       return;
    }

    dfsDict(i + 1, len, dist + 1);

    if (dist >= 5) {
        char tmp = buffer[i];
        buffer[i] = '-';
        dfsDict(i + 1, len, 1);
        buffer[i] = tmp;
    }
}

void init() {
    FILE* pFile = fopen("./garbled_email_dictionary.txt" , "r"); 
    size_t maxLen = 0;

    while (!feof (pFile)) {
        if(fgets(buffer , 32 , pFile) == NULL ) break;
        size_t len = strlen(buffer) - 1;
        buffer[len] = '\0';
        dfsDict(0, len, 5);
        // maxLen = max(maxLen, len);
        // printf("%s %d\n", buffer, len); 
    }
    // printf("%d\n", maxLen);
    // printf("%d\n", dict.size());
    fclose (pFile);
}

void dfs(int s, int k, int d, int delta) {
    if (k > 10) return;
   
    string key(str + s, k);
    if (dict.find(key) != dict.end()) {
       A[s + k][min(5, d)] = min(A[s + k][min(5, d)], delta);
    }

    if(s + k >= n) return;
    
    dfs(s, k + 1, d + 1, delta);
    if (d >= 5) {
        char tmp = str[s + k];
        str[s + k] = '-';
        dfs(s, k + 1, 1, delta + 1);
        str[s + k] = tmp;
    }
}

int solve() { 
    n = strlen(str);
    for (int i = 0; i <= n; i++) {
        for(int j = 1; j < 6; j++) {
            A[i][j] = n;
        }
    }
    A[0][5] = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 1; j < 6; j++) if(A[i][j] < n){
            dfs(i, 0, j, A[i][j]); 
        }
    }
    int ret = n;
    for (int i = 1; i < 6; i++) ret = min(ret, A[n][i]);
    return ret;
}

int main() {
    init();
    int T;
    scanf("%d", &T);
    for (int k = 1; k <=T; k++) {
        scanf("%s", str);
        printf("Case #%d: %d\n", k, solve());
    }
}
