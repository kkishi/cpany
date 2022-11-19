#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n);
  V<int> a(2 * n);
  cin >> a;
  VV<int> p(n);
  rep(i, n * 2) p[a[i] - 1].eb(i);
  V<int> ans(2 * n - 1);
  rep(i, n) {
    sort(p[i]);
    ans[p[i][1] - p[i][0] - 1]++;
  }
  rep(i, sz(ans) - 1) ans[i + 1] += ans[i];
  each(e, ans) wt(e);
}
