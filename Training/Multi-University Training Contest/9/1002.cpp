#include <bits/stdc++.h>

typedef long long LL;
const int N = 100010, M = N << 1;
#define clear(x) memset(x, 0, sizeof x)
int n, m;
LL ans[N];

struct Que {
  int u, v, ty, i, x;
  bool operator<(const Que &a) const { return x < a.x; }
} ask[M];

struct lr {
  int x, i;
  bool operator<(const lr &a) const { return x < a.x; }
} c[N];

LL T[N * 8];

struct Tree {
  int tot, head[N], next[M], to[M], siz[N], son[N], fa[N][17], q[N];
  int seq[N], sta[N], stot, belong[N], dep[N];

  void init() {
    stot = tot = 0;
    // clear(q);
    clear(head);
    clear(fa);
    clear(dep);
    clear(siz);
    clear(son);
    // clear(seq);
    clear(sta);
    clear(belong);
  }

  void add(int x, int y) {
    to[++tot] = y;
    next[tot] = head[x];
    head[x] = tot;
  }

  void bfs() {
    int i, h, t;
    for (q[h = t = 1] = 1; h <= t; ++h)
      for (i = head[q[h]]; i; i = next[i])
        if (to[i] != fa[q[h]][0]) {
          fa[q[++t] = to[i]][0] = q[h];
          dep[to[i]] = dep[q[h]] + 1;
        }
    for (i = t; i; --i) {
      siz[fa[q[i]][0]] += ++siz[q[i]];
      if (!son[fa[q[i]][0]] || siz[son[fa[q[i]][0]]] < siz[q[i]])
        son[fa[q[i]][0]] = q[i];
    }
  }

  void dfs(int now) {
    // printf("%d \n", now);
    seq[sta[now] = ++stot] = now;
    if (son[now]) {
      belong[son[now]] = belong[now];
      dfs(son[now]);
    }
    for (int i = head[now]; i; i = next[i])
      if (to[i] != son[now] && to[i] != fa[now][0])
        dfs(belong[to[i]] = to[i]);
  }

  void Build() {
    bfs();
    dfs(1);
    for (int j = 1; j <= 16; ++j)
      for (int i = 1; i <= n; ++i)
        fa[i][j] = fa[fa[i][j - 1]][j - 1];
  }
} G;

void modify(int t, int l, int r, int x, int v) {
  if (l == r) {
    T[t] = v;
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    modify(t << 1, l, mid, x, v);
  else
    modify(t << 1 | 1, mid + 1, r, x, v);
  T[t] = T[t << 1] + T[t << 1 | 1];
}

LL query(int t, int l, int r, int x, int y) {
  if (x <= l && r <= y)
    return T[t];
  int mid = l + r >> 1;
  LL ret = 0;
  if (x <= mid)
    ret += query(t << 1, l, mid, x, y);
  if (y > mid)
    ret += query(t << 1 | 1, mid + 1, r, x, y);
  return ret;
}

using std::swap;

LL find(int u, int v) {
  int f1 = G.belong[u], f2 = G.belong[v];
  LL ret = 0;
  while (f1 != f2) {
    if (G.dep[f1] < G.dep[f2]) {
      swap(f1, f2);
      swap(u, v);
    }
    ret += query(1, 1, n, G.sta[f1], G.sta[u]);
    u = G.fa[f1][0];
    f1 = G.belong[u];
  }
  if (u == v)
    return ret + query(1, 1, n, G.sta[u], G.sta[u]);
  if (G.dep[u] > G.dep[v])
    swap(u, v);
  return ret + query(1, 1, n, G.sta[u], G.sta[v]);
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &c[i].x);
      c[i].i = i;
    }
    std::sort(c + 1, c + 1 + n);
    G.init();
    memset(T, 0, sizeof(T));
    for (int i = 1, x, y; i < n; ++i) {
      scanf("%d%d", &x, &y);
      G.add(x, y), G.add(y, x);
    }
    G.Build();

    for (int i = 1; i <= m; ++i) {
      int u, v, a, b;
      scanf("%d%d%d%d", &u, &v, &a, &b);
      ask[i + i - 1] = (Que){u, v, -1, i, a - 1};
      ask[i + i] = (Que){u, v, 1, i, b};
    }
    std::sort(ask + 1, ask + 1 + m + m);

    memset(ans, 0, sizeof(ans));
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
      // printf("    %d ", G.sta[i]);
      while (cur <= m + m && ask[cur].x < c[i].x) {
        ans[ask[cur].i] += ask[cur].ty * find(ask[cur].u, ask[cur].v);
        //    printf("    %d %d %lld\n", ask[cur].u, ask[cur].v
        //    ,find(ask[cur].u, ask[cur].v));
        ++cur;
      }
      modify(1, 1, n, G.sta[c[i].i], c[i].x);
    }
    while (cur <= m + m) {
      ans[ask[cur].i] += ask[cur].ty * find(ask[cur].u, ask[cur].v);
      ++cur;
    }
    for (int i = 1; i < m; ++i) {
      printf("%lld ", ans[i]);
    }
    printf("%lld\n", ans[m]);
  }

  return 0;
}
