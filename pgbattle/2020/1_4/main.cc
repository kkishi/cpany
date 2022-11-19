#include <bits/stdc++.h>

#include "cpany.h"
#include "graph.h"

void Main() {
  ints(n, m);
  Graph g(n);
  Graph rg(n);
  rep(m) {
    ints(a, b);
    g[a - 1].eb(b - 1);
    rg[b - 1].eb(a - 1);
  }
  queue<int> que;
  V<int> dist(n, big);
  que.push(n - 1);
  dist[n - 1] = 0;
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    each(child, rg[node]) {
      if (chmin(dist[child], dist[node] + 1)) {
        que.push(child);
      }
    }
  }
  if (dist[0] == big) {
    wt(-1);
  } else {
    V<int> ans;
    int node = 0;
    while (true) {
      ans.pb(node + 1);
      if (node == n - 1) break;
      int next = big;
      each(child, g[node]) {
        if (dist[child] == dist[node] - 1) chmin(next, child);
      }
      node = next;
    }
    wt(ans);
  }
}
