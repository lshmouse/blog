#include <stdio.h>
#include <algorithm>

#define llong long long

llong n, k, p;

bool check(llong mid) {
  llong  left = n - k * mid;
  llong vote = std::min(k, left);
  if (vote * 100 >= left *p) return true;
  else return false;
}

llong findLast() {
  llong begin = 0;
  llong end = (n - 1) / k;
  llong ret = 0;
  while (begin <= end) {
    llong mid = (begin + end) / 2;
    if (check(mid)) {
      end = mid - 1;
      ret = mid + 1;
    }
    else {
      begin = mid + 1;
    }
  }
  return n - ret * k;
}

llong findFirst() {

}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%lld%lld%lld", &n, &k, &p);
    llong last = findLast();

  }
}
