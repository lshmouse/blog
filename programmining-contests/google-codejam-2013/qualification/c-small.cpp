#include <stdio.h>

#define llong long long
llong a, b ;

llong base(llong v) {
    llong base = 1;
    while (v > 0) {
        base = 10 * base;
        v = v /10;
    }
    return base;
}

llong reverse(llong v) {
    llong y = 0;
    while (v > 0) {
        y = y * 10 + v%10;
        v = v /10;
    }
    return y;
}

int solve(llong limit) {
    int ret = 0;
    for (llong i = 0; i < 10000; i++) {
        llong p = i * base(i) + reverse(i);
        long pow = p * p;
        if (pow > limit) break;
        if (reverse(pow) == pow)  {
            ret ++;
        }
    }
    
    for (llong i = 0; i < 10000; i++) {
        llong p = i / 10 * base(i) + reverse(i);
        long pow = p * p;
        if (pow > limit) break;
        if (reverse(pow) == pow)  {
            ret ++;
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1 ; t <= T ;t ++) {
       scanf("%lld%lld", &a, &b);
       printf("Case #%d: %d\n", t, solve(b) - solve(a -1));
    }
}
