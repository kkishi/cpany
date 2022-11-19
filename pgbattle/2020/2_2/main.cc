#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n);
  string x = to_string(1LL << n);
  x = string(n - sz(x), '0') + x;
  wt("0." + x);
}
