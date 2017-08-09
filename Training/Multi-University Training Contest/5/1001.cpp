#include <bits/stdc++.h>

using std::bitset;
const int N = 50001;
bitset<N> cnt, B;
bool ans[N];
int n, m, q, Tc;
bool vis[N];

int aa;
char ch;
int F() {
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  aa = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9')
    aa = aa * 10 + ch - '0';
  return aa;
}
int main() {
  for (scanf("%d", &Tc); Tc--;) {
    cnt.reset();
    B.reset();
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
      cnt.flip(x);
    }
    for (int i = 1, x, j; i <= m; ++i) {
      scanf("%d", &x);
      vis[x] = 1;
      for (j = 0; j < N; j += x)
        B.flip(j);
    }

    for (int i = 0, j, x; i < N; ++i) {
      ans[i] = (B & cnt).count() & 1;
      cnt >>= 1;
      if (i + 1 != N && vis[i + 1]) {
        x = i + 1;
        for (j = 0; j < N; j += x)
          B.flip(j);
      }
    }
    for (int i = 1, x; i <= q; ++i) {
      scanf("%d", &x);
      printf("%d\n", ans[x]);
    }
  }
  return 0;
}
