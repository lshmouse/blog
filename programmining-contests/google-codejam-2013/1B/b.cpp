#include <stdio.h>
#include <string.h>
#include <math.h>

#include <vector>
#include <algorithm>

using namespace std;

int n, x, y;

double calc(int n, int k) {
    double ret = 1.0;
    for (int i = k + 1; i <= n; i++) { 
        ret*= i;
        ret/= (i -k);
    }
    for (int i = 1; i <= n; i++) ret/= 2;
    return ret;
}

double solve() {
    int level = -1;
    for (int i = 0; n >=0; i++) {
       if (n >= (4 *i + 1)) {
           n -= (4*i + 1); 
           level = i;
       } else {
           break;
       }
    }
    if (x + y <= 2 * level) return 1.0;
    if (x + y > 2 * (level + 1)) return 0.0;
    
    int need = 2*level + 2 -x + 1;

    if (n >= (need + (2* level + 2))) return 1.0;
    if (n < need) return 0.0;
    
    if (x == 0) return 0.0;

    double ret = 0.0;
    for (int i = 0; i < need; i++) ret += calc(n, i);
    return 1.0 - ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <=T; k++) {
        scanf("%d%d%d", &n, &x, &y);
        if (x <=0) x = -x;
        printf("Case #%d: %f\n", k, solve());
    }
}
