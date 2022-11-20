#include <bits/stdc++.h>

#include "cpany.h"
#include "graph.h"

void Main() {
  ints(n);
  WeightedGraph<int> g(n);
  g.Read();
  int a = -1, b = -1, ab = -1;
  Fix([&](auto rec, int node, int parent) -> int {
    int ret = 1;
    each(child, weight, g[node]) {
      if (child == parent) continue;
      int res = rec(child, node);
      if (res == n / 2) {
        a = node;
        b = child;
        ab = weight;
      }
      ret += res;
    }
    return ret;
  })(0, -1);
  if (a == -1) {
    wt(0);
    return;
  }
  auto dfs =
      Fix([&](auto rec, V<int>& v, int node, int parent, int dist) -> void {
        v[node] = dist;
        each(child, weight, g[node]) {
          if (child == parent) continue;
          rec(v, child, node, dist + weight);
        }
      });
  V<int> da(n), db(n);
  dfs(da, a, -1, 0);
  dfs(db, b, -1, 0);
  int ans = 0;
  rep(2) {
    const bool naive = false;
    if (!naive) {
      // Fast implementation.
      V<int> v;
      rep(q, n) {
        int qa = da[q];
        int qb = db[q];
        if (qb < qa) {
          v.eb(qb);
        }
      }
      sort(v);
      rep(p, n) {
        int pa = da[p];
        int pb = db[p];
        if (pa < pb) {
          auto it = lower_bound(all(v), pa - ab + 1);
          auto jt = lower_bound(all(v), pb + 1);
          ans += jt - it;
        }
      }
    } else {
      // Naive implementation.
      rep(p, n) {
        int pa = da[p];
        int pb = db[p];
        rep(q, n) {
          int qa = da[q];
          int qb = db[q];
          if (pa < qa && pb >= qb) {
            ++ans;
          }
        }
      }
    }
    swap(a, b);
    swap(da, db);
  }
  wt(ans);
}
