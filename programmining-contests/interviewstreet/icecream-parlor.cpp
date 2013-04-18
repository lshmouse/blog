#include <stdio.h>

#define maxn 10240

int n, C;
int A[maxn], index[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d", &C);
        scanf("%d", &n);
        for(int i = 0; i < n ;i ++){
            scanf("%d", &A[i]);
        }
        for(int i = 0; i < maxn; i++) index[i] = -1;
        for (int i = 0; i < n ;i ++) {
            if (A[i] <= C) {
                int left = C - A[i]; 
                if (index[left] != -1) {
                    printf("%d %d\n", index[left] +1, i +1);
                    break;
                }
            }
            index[A[i]] = i;
        }
    }
    return 0;
}
