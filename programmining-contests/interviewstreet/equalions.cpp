#include <stdio.h>

#define MOD 1000007
#define LL long long


LL Count(int n, int p) {
    LL count = 0 ;
    while (n > 0) {
        count += n/p;
        n = n/p;
    }
    return count;
}

LL Solved(int n) {
    LL ret = 1;
    bool flag[n+1];

    flag[0] = flag[1] =false;
    for (int i = 2 ; i< n+1; i++) flag[i]= true;
    for (int i = 2; i < n+1; i++) {
        if (flag[i]) {
            for (LL j = i; (i * j) < n +1 ; j++) {
                flag[(int)(i*j)] = false;
            }
            LL count = Count(n, i);
            ret = ret * ((2* count + 1) % MOD) % MOD;
        }
    }
    return ret;
}

int main(){
    int n;
    while (1 == scanf("%d", &n)) {
        printf("%lld\n", Solved(n));
    }
    return 0;
}
