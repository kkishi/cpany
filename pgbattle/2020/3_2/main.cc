#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n, s);
  V<int> a(n);
  Fix([&](auto rec, int depth, int sum) {
    int last = depth == 0 ? 1 : a[depth - 1];
    int rem = s - sum;
    if (depth == n - 1) {
      a[depth] = rem;
      if (a[depth] >= last) {
        wt(a);
      }
      return;
    }
    rep(i, last, rem / (n - depth) + 1) {
      a[depth] = i;
      rec(depth + 1, sum + i);
    }
  })(0, 0);
}
