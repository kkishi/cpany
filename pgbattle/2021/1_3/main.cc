#include <bits/stdc++.h>

#include "cpany.h"
#include "modint.h"

using mint = ModInt<998244353>;

void Main() {
  ints(n, m, a, b);
  wt(mint::Comb(n + m, m) -
     mint::Comb(a + b, b) * mint::Comb(n + m - (a + b), n - a));
}
