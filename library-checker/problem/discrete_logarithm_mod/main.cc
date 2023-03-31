#include <bits/stdc++.h>

#include "cpany.h"
#include "discrete_log.h"

void Main() {
  ints(t);
  rep(t) {
    ints(x, y, m);
    wt(DiscreteLog(x, y, m));
  }
}
