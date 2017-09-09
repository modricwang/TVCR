#include <bits/stdc++.h>

const int N = 10010, M = 200010;
using std::max;

int tot, next[M], head[N], c[M], to[M];
int n, m, q[N], in[N], dis[N];

void add(int x, int y, int z) {
  to[++tot] = y;
  next[tot] = head[x];
  head[x] = tot;
  c[tot] = z;
}

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d", &n, &m);
    memset(in, 0, sizeof in);
    tot = 0;
    memset(head, 0, sizeof head);
    memset(dis, 0, sizeof dis);
    for (int i = 1, x, y, z; i <= m; ++i) {
      scanf("%d%d%d", &x, &y, &z);
      add(x, y, z);
      in[y]++;
    }
    int h = 1, t = 0;
    for (int i = 1; i <= n; ++i)
      if (!in[i])
        q[++t] = i;
    for (; h <= t; ++h) {
      for (int i = head[q[h]]; i; i = next[i]) {
        --in[to[i]];
        dis[to[i]] = max(dis[q[h]] + c[i], dis[to[i]]);
        if (in[to[i]] == 0)
          q[++t] = to[i];
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
      ans = max(ans, dis[i]);
    printf("%d\n", ans);
  }
  return 0;
}
