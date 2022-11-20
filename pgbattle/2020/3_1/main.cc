#include <bits/stdc++.h>

#include "cpany.h"
#include "graph.h"

void Main() {
  ints(n);
  Graph g(n);
  g.Read();
  int ans = 0;
  Fix([&](auto rec, int node, int parent) -> void {
    bool cango = false;
    each(child, g[node]) {
      if (child == parent) continue;
      rec(child, node);
      cango = true;
    }
    if (!cango) ++ans;
  })(0, -1);
  wt(ans);
}
