#include <stdio.h>
int main() {
  int T, n, x;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &n);
    int lines = 0;
    int segs = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      lines += (x + 1);
      segs += x;
    }
    int ret = 1 + 1LL * lines * (lines + 1) / 2 - 2 * segs;
    printf("Case #%d: %d\n", t, ret);
  }
  return 0;
}
