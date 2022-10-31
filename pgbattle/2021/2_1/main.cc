#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(p);
  auto comb = [](int n, int m) {
    int p = 1, q = 1;
    rep(i, m) {
      p *= n - i;
      q *= m - i;
    }
    return p / q;
  };
  double ans = 0;
  rep(i, 4, 8) {
    ans += pow(p / 100.0, i) * pow((100 - p) / 100.0, 7 - i) * comb(7, i);
  }
  wt(ans * 100);
}
