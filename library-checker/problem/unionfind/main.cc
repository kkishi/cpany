#include <bits/stdc++.h>

#include "cpany.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  DisjointSet ds(n);
  rep(q) {
    ints(t, u, v);
    if (t == 0) {
      ds.Union(u, v);
    } else {
      wt(ds.Same(u, v) ? 1 : 0);
    }
  }
}
