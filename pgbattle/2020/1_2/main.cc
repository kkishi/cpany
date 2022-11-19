#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;
  int A = accumulate(a), B = accumulate(b);
  wt(A > B ? "A" : A < B ? "B" : "same");
}
