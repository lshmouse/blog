#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define maxn 51200
#define maxm 1024000

struct seg {
    int l, r; // [a, b)
    int len;
    int cov; //被覆盖的次数
};

seg tree[maxn * 4];

void init(int left,int right,int k) {
    tree[k].l = left;
    tree[k].r = right;
    tree[k].len = 0;
    tree[k].cov = 0;

    if(left + 1 == right) return;
    
    int mid = (left + right) / 2;
    init(left, mid, 2 * k );
    init(mid, right, 2 * k + 1);
}

void update(int left,int right,char flag, int k) {
    if(left <= tree[k].l && tree[k].r <= right) {
        if(flag == 1){
            tree[k].len = tree[k].r - tree[k].l;
            tree[k].cov ++;
        }
        else {
            tree[k].cov --;
            if(tree[k].cov == 0) {
                if(tree[k].l + 1 == tree[k].r) 
                    tree[k].len = 0;
                else
                    tree[k].len = tree[k<<1].len + tree[k<<1|1].len; 
            }
        }
        return;
    }

    if(left < tree[2 * k].r)
        update(left, right, flag, 2 * k);

    if(right > tree[2 * k + 1].l)
        update(left, right,flag, 2 * k + 1);

    if(tree[k].cov == 0)          
        tree[k].len = tree[k<<1].len + tree[k<<1|1].len;
}

struct VLine {
    int x, y1, y2;
    char flag;   
};

bool cmp(VLine vl1,VLine vl2)
{
    return vl1.x < vl2.x;
}

VLine VL[maxm * 8];
int tail;

void AddRect(int x1,int y1,int x2,int y2) {
    VL[tail].x = x1;
    VL[tail].y1 = y1;
    VL[tail].y2 = y2;
    VL[tail].flag = 1;
    tail++;

    VL[tail].x = x2;
    VL[tail].y1 = y1;
    VL[tail].y2 = y2;
    VL[tail].flag = -1;
    tail++;
}

int W, H, P, Q, n, a, b, c, d, X, Y;
int x[maxm], y[maxm];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        tail = 0;

        scanf("%d%d%d%d%d%d%d%d%d%d%d", &W, &H, &P, &Q, &n, &X, &Y, &a, &b, &c, &d);

        x[0] = X; y[0] = Y;
       
        for (int i = 1; i < n; i++) {
            x[i] = (x[i-1] * a + y[i-1] * b + 1) % W;
            y[i] = (x[i-1] * c + y[i-1] * d + 1) % H;
        }

        tail = 0;
        for (int i = 0; i < n; i++) {
            int x1 = max(0, x[i] - P + 1);
            int y1 = max(0, y[i] - Q + 1);
            int x2 = min(x[i] + 1, W - P + 1);
            int y2 = min(y[i] + 1, H - Q + 1);
            
            if (x1 < x2 && y1 < y2) 
                AddRect(x1, y1, x2, y2);
        }
        
        sort(VL,VL + tail,cmp);

        init(0, H, 1);
        update(VL[0].y1,VL[0].y2,VL[0].flag,1);        

        int ret = 0;
        for(int i = 1; i < tail; i++) {
            ret += (VL[i].x - VL[i-1].x ) * tree[1].len;
            update(VL[i].y1, VL[i].y2, VL[i].flag, 1);
        }
        printf("Case #%d: %d\n", t, (W - P + 1)* (H - Q + 1) - ret);
    }
    return 0;
}
