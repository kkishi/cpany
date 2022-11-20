#include <bits/stdc++.h>

#include "cpany.h"
#include "graph.h"

void Main() {
  ints(n, m, t, k);
  WeightedGraph<pair<int, int>> g(n);
  rep(m) {
    ints(a, b, c, d);
    --a, --b;
    g[a].eb(b, pair{c, d});
    g[b].eb(a, pair{c, d});
  }
  // Dijkstra
  low_priority_queue<pair<int, int>> que;
  V<int> dist(n, big);
  auto push = [&](int state, int cost) {
    if (chmin(dist[state], cost)) que.emplace(cost, state);
  };
  push(0, 0);
  while (!que.empty()) {
    auto [cost, state] = que.top();
    que.pop();
    if (dist[state] < cost) continue;
    each(nstate, attr, g[state]) {
      auto [c, d] = attr;
      int ncost;
      int x = d - k;
      if (x < 0 || (cost + c <= t - x || t + x <= cost)) {
        ncost = cost + c;
      } else {
        ncost = t + x + c;
      }
      push(nstate, ncost);
    }
  }
  int ans = dist[n - 1];
  if (ans == big) ans = -1;
  wt(ans);
}
