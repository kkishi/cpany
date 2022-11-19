#include <bits/stdc++.h>

#include "cpany.h"
#include "modint.h"

using mint = ModInt<998244353>;

V<int> KMP(const string& w) {
  V<int> t(sz(w) + 1);
  int pos = 1;
  int cnd = 0;
  t[0] = -1;
  while (pos < sz(w)) {
    if (w[pos] == w[cnd]) {
      t[pos] = t[cnd];
    } else {
      t[pos] = cnd;
      while (cnd >= 0 && w[pos] != w[cnd]) {
        cnd = t[cnd];
      }
    }
    ++pos;
    ++cnd;
  }
  t[pos] = cnd;
  return t;
}

void Main() {
  strings(s);
  V<int> t = KMP(s);
  int n = sz(s);
  V<mint> dp(n + 1);
  rep(i, n) dp[i + 1] = 2 * dp[i] - dp[t[i] + 1] + 2;
  wt(dp[n]);
}
