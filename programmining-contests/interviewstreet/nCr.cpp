#include <stdio.h>
#include <vector>

#include <algorithm>

using namespace std;

#define maxn 128

#define MOD 142857

vector<int> p, nums;

int A[4], B[4];
int C[maxn][maxn];
int left[27];

void init() {
    for (int i =0 ;i < maxn; i++) C[i][0]=C[i][i] =1;
    for (int i = 2; i < maxn; i++){
        for (int j = 1; j < maxn; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
    int pre = 1;
    for (int i = 0; i < 27; i++) if ((i % 3) != 0){
        left[i] = pre * (i % 27) % 27;
        pre = left[i];
    } else {
        left[i] = pre;
    }
}

int getReverse(int a, int pk) {
    for (int i = 0; i < pk; i++) if ((i * a )% pk ==  1) return i;
    return 0;
}

int power(int a, int b, int pk) {
    if (b == 0) return 1 % pk;
    else if ((b%2) == 1) return power(a, b-1, pk) * a % pk;
    else {
        int t = power(a, b / 2, pk);
        return t * t % pk;
    }
}

int calc(int n, int p, int pk) {
    return power(left[26], n / pk, pk) * left[n%pk] % pk;
}

int solve(int n, int r, int p, int pk) {
    if (n < pk) {
        return C[n][r] % pk;
    }

    int mod_a = calc(n, p, pk);
    
    int mod_b = calc(n-r, p, pk) * calc(r, p, pk) % pk;
        
    printf("---%d %d %d\n", mod_a, mod_b, getReverse(mod_b, pk));

    int ret = mod_a * getReverse(mod_b, pk) % pk;
   
    ret = ret * power(p, n / p - r/p - (n-r)/p, pk) % pk ;
   
    ret = ret * solve(n/p, r/p, p, pk) % pk;
    
    return ret;
}

int fast_mod(int n, int r, int p) {
    int ans = 1;
    for (int a= n, b = r; a > 0 && b > 0; a /=p, b/=p) {
        ans = ans * C[a % p][b % p] % p; 
    }

    return ans;
}

int extended_euclid(int a, int b, int &x, int &y) {  
    int d;  
    if(b == 0) {x = 1; y = 0; return a;}  
    d = extended_euclid(b, a % b, y, x);  
    y -= a / b * x;  
    return d;  
}  

int chinese_remainder(int* b, int* w, int len) {   
    int i, d, x, y, m, n, ret;  
    ret = 0; n = 1;   
    for(i=0; i < len ;i++) n *= w[i];  
    for(i=0; i < len ;i++) {   
        m = n / w[i];  
        d = extended_euclid(w[i], m, x, y);  
        ret = (ret + y*m*b[i]) % n;  
    }  
    return (n + ret%n) % n;  
}  

int main () {
    init();
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int a, b;
        scanf("%d%d", &a, &b);
        
        A[0] = 11; B[0] = fast_mod(a, b, 11);
        A[1] = 13; B[1] = fast_mod(a, b, 13);
        A[2] = 37; B[2] = fast_mod(a, b, 37);
        A[3] = 27; B[3] = solve(a, b, 3, 27);
        
        printf("%d-----%d---- %d\n", A[3], B[3], C[a][b] % 27);
        
        printf("%d\n", chinese_remainder(B, A, 4));
    }
    return 0;
}
