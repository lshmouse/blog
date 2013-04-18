#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define maxn 200000
#define llong long long

bool flag[maxn];
vector<int> p;
int n, sum[4];

llong multi(llong a, llong b, llong MOD) {
  if (b == 0) return 0;
  return (a * (b % 10) % MOD + 10 * multi(a, b /10, MOD) % MOD) % MOD;
}

llong power(llong a, llong b, llong mod) {
  if (b == 0) return 1 % mod;
  if (b == 1) return a % mod;

  if (b % 2 == 0) {
    llong t = power(a, b/2, mod);
    return multi(t,  t , mod);
  } else {
    return multi(a , power(a, b-1, mod),  mod);
  }
}

bool isSqure(llong x) {
  llong y = (llong)sqrt(double(x));
  if (y*y == x) return true;
  if ((y+1) * (y+1) == x) return true;
  return false;
}

bool isPrime(llong x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x == 3) return true;

  srand((int)time(0));

  for (int i = 1; i < 100; i++) {
    llong s = rand() % (x - 2) + 2;
    if (power(s, x - 1, x) != 1) return false;
  }
  return true;
}

void init() {
   memset(flag, true, sizeof(flag[0]) * maxn);
   flag[0] = flag[1] = false;
   for (llong i = 2; i < maxn; i ++) {
      if (flag[i]) {
         p.push_back(i);
         for (long j = i; i * j < maxn; j++)
            flag[(int)(i*j)] = false;
      }
   }
}

int main() {
    init(); 
    while(1 == scanf("%d", &n) ) {
        memset(sum, 0, sizeof(sum[0]) * 4);
        llong in;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &in);
            int a  = 0, b = 1;
            for (int j = 0; j < p.size(); j ++) {
                if (in <= 1) break;
                if (in % p[j] == 0) {
                    a++;

                    int count = 0;
                    while (in % p[j] == 0) {
                        count++;
                        in = in / p[j];
                    }

                    b *= (1 + count * (p[j] % 2)) % 2;
                }
            }
            if (in > 1) {
                if (isPrime(in)) { // p 
                  a +=1;
                  b *= (1 + 1 * (in % 2)) % 2; 
                } else if(isSqure(in)){ // p * p
                  a +=1;
                  b*= (1 + 2) % 2;
                } else { // p1 * p2
                  a +=2;
                  b*= (1 + 1 * 1) % 2 * (1 + 1 * 1) % 2;
                }
            }
            sum[a % 2] ++;
            sum[2 + b % 2] ++;
        }
        int ret = 0;
        for (int i = 0; i < 4; i++) ret =  max(ret, sum[i]);
        printf("%d\n", ret);
    }
}
