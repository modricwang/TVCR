#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 20010, M = 1000010;
typedef long long LL;

LL ans[M], cnt[M];
struct Edge {
  int u, v, x;
  bool operator<(const Edge &a) const { return x < a.x; }
} e[M];

struct Que {
  int i, x;
  bool operator<(const Que &a) const { return x < a.x; }
} q[M];

int f[N], Qc, n, m, siz[N];

int get(int u) { return f[u] == u ? u : f[u] = get(f[u]); }

int find(int x) {
  int l = 0, r = Qc, mid;
  while (l != r) {
    mid = l + r + 1 >> 1;
    if (q[mid].x > x)
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i <= n; ++i)
      siz[f[i] = i] = 1;
    for (int i = 0; i < m; ++i)
      scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].x);
    std::sort(e, e + m);
    scanf("%d", &Qc);
    for (int i = 1; i <= Qc; ++i) {
      cnt[i] = ans[i] = 0;
      q[i].i = i;
      scanf("%d", &q[i].x);
    }
    std::sort(q + 1, q + 1 + Qc);
    for (int i = 0; i < m; ++i) {
      int u = get(e[i].u), v = get(e[i].v);
      if (u == v)
        continue;
      // printf("	%d %d\n", e[i].x, find(e[i].x));
      cnt[find(e[i].x)] += 2LL * siz[u] * siz[v];
      f[u] = v;
      siz[v] += siz[u];
    }
    LL now = 0;
    for (int i = Qc; i; --i) {
      now += cnt[i];
      ans[q[i].i] = now;
      //	printf("now : %lld ", now);
    }
    for (int i = 1; i <= Qc; ++i)
      printf("%lld\n", ans[i]);
  }
  return 0;
}
