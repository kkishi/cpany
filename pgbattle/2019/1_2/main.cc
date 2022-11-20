#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  strings(s);
  if (s == "AtCoder") {
    wt("Yes");
  } else {
    each(e, s) e = tolower(e);
    if (s == "atcoder") {
      wt("Maybe");
    } else {
      wt("No");
    }
  }
}
