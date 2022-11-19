#include <bits/stdc++.h>

#include "cpany.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> r(n);
  cin >> r;
  int ma = max(r);
  vector dp(n + ma + 1, mint(0));
  vector ddy(n + ma + 1, mint(0));
  mint y = 0;
  mint dy = 0;
  auto triangle = [&](int i, int h, mint p) {
    mint q = p / (h * (h + 1) / 2);
    y += q * h;
    ddy[i] -= q;
    ddy[i + h] += q;
  };
  triangle(0, 1, 1);
  rep(i, n + ma) {
    dp[i] = y;
    dy += ddy[i];
    y += dy;
    if (i < n) {
      triangle(i + 1, r[i], dp[i]);
    }
  }
  mint ans = 0;
  rep(i, n, sz(dp)) ans += dp[i] * (i + 1);
  wt(ans);
}
