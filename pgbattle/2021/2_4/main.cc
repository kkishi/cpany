#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n, m);
  V<int> p(n);
  cin >> p;
  V<tuple<int, int, int>> v;  // {width, left, right}
  auto push = [&](int l, int r) { v.eb(r - l, l, r); };
  rep(m) {
    ints(a, b);
    --a;
    // This is added later, so it is not necessary.
    if (b - a == 1) continue;
    push(a, b);
  }
  rep(i, n) push(i, i + 1);
  push(0, n);
  sort(v);
  int N = sz(v);
  V<int> l_to_vi(n, -1);
  VV<int> children(N);
  rep(i, sz(v)) {
    auto [_, l, r] = v[i];
    int& todo_seti = l_to_vi[l];
    while (l < r) {
      int vi = l_to_vi[l];
      if (vi == -1) break;
      children[i].eb(vi);
      l = get<2>(v[vi]);
    }
    todo_seti = i;
  }

  V<bool> seen(N);
  V<pair<int, bool>> memo(N);  // {min, reversed}
  Fix([&](auto rec, int node) -> pair<int, bool> {
    auto& ret = memo[node];
    if (!seen[node]) {
      seen[node] = true;
      const V<int>& c = children[node];
      if (c.empty()) {
        ret = {p[get<1>(v[node])], false};
      } else {
        assert(sz(c) >= 2);
        V<int> res;
        // Call rec for each child to ensure that memo is all filled.
        each(c, children[node]) res.eb(rec(c).first);
        if (res[0] < res.back()) {
          ret = {res[0], false};
        } else {
          ret = {res.back(), true};
        }
      }
    }
    return ret;
  })(N - 1);

  V<int> ans;
  Fix([&](auto rec, int node) -> void {
    const V<int>& c = children[node];
    auto [v, rev] = memo[node];
    if (c.empty()) {
      ans.eb(v);
    } else {
      if (rev) {
        rrep(i, sz(c)) rec(c[i]);
      } else {
        each(e, c) rec(e);
      }
    }
  })(N - 1);
  wt(ans);
}
