#include <bits/stdc++.h>

#include "binary_search.h"
#include "cpany.h"

void Main() {
  ints(t);
  rep(t) {
    ints(n, m);
    auto nc2 = [](int n) { return n * (n - 1) / 2; };
    int x = BinarySearch<int>(n, 0, [&](int x) { return nc2(x) >= m; });
    wt(max(1, n - m), n - x + 1);
  }
}
