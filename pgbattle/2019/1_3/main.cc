#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n, m);
  set<int> st;
  rep(i, n) {
    ints(a, b);
    st.insert(i - (a + b));
  }
  int ans = 0;
  rep(i, m) {
    if (st.count(i)) {
      ++ans;
    }
  }
  wt(ans);
}
