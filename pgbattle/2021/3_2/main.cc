#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n, s);
  V<int> d(n);
  cin >> d;
  int mi = 0, ma = 0;
  V<int> ten(11);
  ten[0] = 1;
  rep(i, 1, 11) ten[i] = ten[i - 1] * 10;
  each(e, d) {
    mi += ten[e - 1];
    ma += ten[e] - 1;
  }
  dbg(mi, ma);
  if (mi <= s && s <= ma) {
    V<int> a(n);
    rep(i, n) a[i] = ten[d[i] - 1];
    int rem = s - accumulate(a);
    rep(i, n) {
      int x = min(rem, (ten[d[i]] - 1 - a[i]));
      a[i] += x;
      rem -= x;
    }
    dbg(rem);
    wt(a);
  } else {
    wt(-1);
  }
}
