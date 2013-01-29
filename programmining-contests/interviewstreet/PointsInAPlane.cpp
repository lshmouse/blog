/* Enter your code here. Read input from STDIN. Print output to STDOUT */
/*
 * using dp to solve this problem
 *
 */

#include <stdio.h>

#include <vector>

using namespace std;

#define MOD 1000000007


class Point{
public:
    bool OneLine(const Point& a, const Point& b) const {
        return (a.x - x) *(b.y - y) - (a.y - y)*(b.x - x) == 0;
    }
public:
    int x, y;
};


bool OneLine(const vector<Point>& points, const vector<int> ids) {
    if (ids.size() == 0) return false;
    if (ids.size() <= 2) return true;
    for(int i = 2; i < ids.size(); i++) {
        if (!points[ids[0]].OneLine(points[ids[1]], points[ids[i]])) {
            return false;
        }
    }
    return true;
}

bool flag[1<<16];
int A[1<<16], B[1<<16], C[1<<16], D[1<<16];

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        int n;
        scanf("%d", &n);
        vector<Point> points(n);
        for (int i = 0; i <n ;i++) {
            scanf("%d%d", &points[i].x, &points[i].y);
        }
        for(int i = 0; i < (1<<n); i++) {
            flag[i] = false;
        }
        for (int i = (1<<n) - 1; i > 0; i--) if (flag[i] == false){
            vector<int> ids;
            for (int j = 0; j < n ;j++) {
                if ((i & (1<<j)) > 0) {
                    ids.push_back(j);
                }
            }
            if (OneLine(points, ids)) {
                for(int j = i; j > 0; j = i & (j - 1)) {
                    flag[j] = true;
                    C[j] = i;
                }
            }
        }

        A[0] = 0; B[0] = 1; D[0] = 0;
        for (int i = 1; i < (1<<n); i++) {
            A[i] = n; B[i] = 0; D[i] = 0;
            for (int j = i; j > 0; j = i & (j-1)) {
                // D[i -j]  表示已经cover的
                if ((D[i - j]&j) == j) continue;
                if (flag[j]) {
                    if (A[i] > A[i-j] + 1) {
                        A[i] = A[i - j] + 1;
                        D[i] = D[i - j] | C[j];
                    }
                }
            }
            for (int j = i; j > 0; j = i & (j-1)) {
                if ((D[i - j]&j) == j) continue;
                if (flag[j]) {
                    if (A[i - j] + 1 == A[i]){
                        B[i] = (B[i] + B[i - j]) % MOD;
                    }
                }
            }
        }
        printf("%d %d\n", A[(1<<n) - 1], B[(1<<n) - 1]);
    }
    return 0;
}
