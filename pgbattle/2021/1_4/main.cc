#include <bits/stdc++.h>

#include "cpany.h"
#include "cumulative_sum.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n);
  V<int> a(n), s(n);
  cin >> a >> s;

  V<mint> dp(n);
  mint sum = 0;
  rep(i, n) {
    sum += s[i];
    dp[i] = dp[i - 1] + sum;
  }

  mint ans = 0;

  set<int> st;
  int l = 0, r = 0;
  while (true) {
    int pr = r;
    while (r < n && !st.count(a[r])) {
      st.insert(a[r]);
      ++r;
    }
    ans += dp[r - l - 1];
    if (l < pr) {
      ans -= dp[pr - l - 1];
    }
    if (r == n) break;
    while (st.count(a[r])) {
      st.erase(a[l]);
      ++l;
    }
  }

  wt(ans);
}
