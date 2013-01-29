#include <stdio.h>

#define MOD 1000000007
#define llong long long

// g(n) = 2^n 
llong g(int n) {
    if (n == 0) return 1;
    if (n%2 == 0) {
        llong tmp = g(n/2);
        return tmp * tmp % MOD;
    } else {
        return 2 * g(n -1) % MOD;
    }
}

// f(n) = n! = 1*2*...*n
llong f(int n) {
    if (n == 0) return 1;
    if (n%2 == 0) {
        llong tmp = f(n/2);
        return g(n/2) * tmp * tmp % MOD;
    } else {
        return n * f(n -1) % MOD;
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int k = 0; k < cases; ++k) {
        int n;
        scanf("%d", &n);
        llong ret = n * (n -1) / 2 * f(n -2) % MOD; 
        printf("%lld\n", ret);
    }
    return 0;
}
