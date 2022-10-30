#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  strings(x);
  rep(i, sz(x)) if (x[i] == '0') {
    x[i] = '1';
    rep(j, i + 1, sz(x)) x[j] = '1';
    break;
  }
  wt(x);
}
