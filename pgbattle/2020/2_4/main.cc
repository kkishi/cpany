#include <bits/stdc++.h>

#include "cpany.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(h, w);
  vector dp(1 << h, mint(0));
  dp[0] = 1;
  rep(w) {
    vector ndp(1 << h, mint(0));
    rep(i, 1 << h) {
      int ni = 0;
      int I = i;
      Fix([&](auto rec, int depth) {
        if (depth == h) {
          ndp[ni] += dp[I];
          return;
        }
        if (!hasbit(i, depth)) {
          ni ^= 1 << depth;
          rec(depth + 1);
          ni ^= 1 << depth;
          if (depth + 1 < h && !hasbit(i, depth + 1)) {
            i ^= 1 << (depth + 1);
            rec(depth + 1);
            i ^= 1 << (depth + 1);
          }
        } else {
          rec(depth + 1);
        }
      })(0);
      assert(i == I);
    }
    swap(dp, ndp);
  }
  wt(dp[0]);
}
