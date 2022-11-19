#include <bits/stdc++.h>

#include "cpany.h"

void Main() {
  ints(h, w);
  ints(px, py, qx, qy);
  --px, --py, --qx, --qy;
  V<string> s(h);
  cin >> s;
  vector dist(h, vector(w, vector(4, big)));
  dist[px][py][0] = 0;
  queue<tuple<int, int, int>> que;
  que.emplace(px, py, 0);
  while (!que.empty()) {
    auto [r, c, d] = que.front();
    que.pop();
    if (r == qx && c == qy) {
      wt(dist[r][c][d]);
      return;
    }
    rep(i, 4) {
      int nd = (d + 3 + i) % 4;
      int dr[] = {-1, 0, 1, 0};
      int dc[] = {0, 1, 0, -1};
      int nr = r + dr[nd];
      int nc = c + dc[nd];
      if (inside(nr, nc, h, w) && s[nr][nc] == '.') {
        if (!chmin(dist[nr][nc][nd], dist[r][c][d] + 1)) {
          wt(-1);
          return;
        }
        que.emplace(nr, nc, nd);
        break;
      }
    }
  }
  wt(-1);
}
