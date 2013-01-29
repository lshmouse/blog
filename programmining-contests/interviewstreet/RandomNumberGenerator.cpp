#include <stdio.h>

int gcd(int a, int b) {
    if (a < b) return gcd(b ,a);
    if (b == 0) return a;
    else return gcd(b, a %b);
}

int main () {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if ( c >= a +b) printf("1/1\n");
        else {
            int sum_all = 2 * a * 2 * b;
            int sum =  4 *c *c / 2;
            if (c >= a) {
                sum = sum - (2*c - 2*a) * (2*c - 2*a) / 2; 
            }
            if (c>= b) {
                sum = sum - (2*c - 2*b) * (2*c - 2*b) / 2; 
            }
            int g = gcd(sum, sum_all);
            printf("%d/%d\n", sum / g, sum_all / g);
        }
    }
}
