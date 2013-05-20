#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

#define maxn 102400
#define llong long long

int n;
llong A[maxn], B[maxn];
int sum[maxn], left[maxn], right[maxn], pre[maxn];
bool flag[maxn];

int lowbit(int t){
    return t & ( t ^ ( t - 1 ) );
} 

int getSum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += sum[x];
        x = x - lowbit(x);
    }
    return ret;
}

void insert(int id, int v) {
    while (id <= n + 1) {
       sum[id] += v;
       id += lowbit(id);
    }
}

int main() {
    while (1 == scanf("%d", &n)) {
        for (int i = 0; i < n ;i ++) {
            scanf("%lld", &A[i]);
            B[i] = A[i];
        }
        sort(B, B + n);
        map<llong, int> order;
        int id = 1;
        for (int i = 0; i < n; i++) {
            if (i > 0 && B[i] > B[i-1]) id ++;
            order[B[i]] = id;
        }
        memset(sum, 0, sizeof(sum[0]) * maxn);
        memset(pre, 0, sizeof(pre[0]) * maxn);
        memset(flag, false, sizeof(flag[0]) * maxn);

        for (int i = 0; i < n; i++) {
           id = order[A[i]];
           int leftSum = getSum(id -1);
           left[i] = leftSum - pre[id];
           if (flag[id] == false) insert(id, 1);
           flag[id] = true;
           pre[id] = leftSum;
        }

        memset(sum, 0, sizeof(sum[0]) * maxn);
        memset(flag, false, sizeof(flag[0]) * maxn);
        
        for (int i = n-1; i >=0 ; i--) {
           id = order.size() + 1 - order[A[i]];
           int leftSum = getSum(id -1);
           right[i] = leftSum;
           if (flag[id] == false) insert(id, 1);
           flag[id] = true;
        }
        llong ret = 0;
        for (int i = 0; i < n; i++) ret += 1L * left[i] * right[i];
        printf("%lld\n", ret);
    }
    return 0;
}
