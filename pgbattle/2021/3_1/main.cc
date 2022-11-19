#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n);
  double sum = 0;
  rep(i, 1, n + 1) sum += log10(i);
  wt(int(1 + floor(sum)));
}
