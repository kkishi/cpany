#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n);
  n = 1 << n;
  map<int, V<int>> mp;
  rep(i, n) {
    ints(a);
    mp[a].eb(i);
  }

  V<int> bests(n);
  Fix([&](auto rec, int l, int r, int depth) {
    if (r - l == 1) return l;
    int m = (r + l) / 2;
    bests[rec(l, m, depth + 1)] = depth;
    return rec(m, r, depth + 1);
  })(0, n, 1);

  V<int> ans;
  rep(i, n) {
    V<int>& v = mp[1 << bests[i]];
    if (v.empty()) {
      wt(-1);
      return;
    }
    ans.eb(v.back() + 1);
    v.pop_back();
  }
  wt(ans);
}
