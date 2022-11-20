#include <bits/stdc++.h>

#include "cpany.h"
#include "modint.h"

using mint = ModInt<>;

void Main() {
  ints(n, m, d);
  V<int> a(m);
  cin >> a;
  each(e, a)-- e;
  int N = div_ceil(n, d) * d;
  map<int, V<int>> mp;
  each(e, a) mp[e % d].eb(e);
  int long_group = 0;   // mod 0 .. n - 1
  int short_group = 0;  // mod n .. N - 1
  mint ans = 0;
  auto f = [](mint l) -> mint { return l * (l + 1) / 2; };
  each(k, v, mp) {
    v.eb(k - d);
    if (k <= (n - 1) % d) {
      ++long_group;
      v.eb(N + k);
    } else {
      ++short_group;
      v.eb(N - d + k);
    }
    sort(v);
    rep(i, sz(v) - 1) {
      int l = (v[i + 1] - v[i]) / d - 1;
      ans += f(l);
    }
  }
  int total_long_group = (n - 1) % d + 1;
  int total_short_group = d - total_long_group;
  ans += (total_long_group - long_group) * f(div_ceil(n, d));
  ans += (total_short_group - short_group) * f(div_floor(n, d));
  wt(ans);
}
