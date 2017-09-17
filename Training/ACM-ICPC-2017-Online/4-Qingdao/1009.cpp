#include <bits/stdc++.h>
#define inf 2147483647
#define clear(x) memset(x, 0, sizeof x)
#define INF(x) memset(x, 63, sizeof x)

const int N = 2005, M = 20005;

struct MaxFlow {
  int head[N], next[M], flow[M], to[M], tot;
  int cur[N], dis[N], q[M * 100], ans, S, T;

  void init() {
    tot = 1;
    ans = 0;
    clear(head);
  }

  inline int min(const int &a, const int &b) { return a < b ? a : b; }

  inline void add(int x, int y, int z) {
    to[++tot] = y;
    next[tot] = head[x];
    head[x] = tot;
    flow[tot] = z;
    to[++tot] = x;
    next[tot] = head[y];
    head[y] = tot;
    flow[tot] = 0;
  }

  void bfs() {
    int h = 0, t = 0;
    INF(dis);
    for (dis[q[h] = T] = 0; h <= t; ++h)
      for (int i = head[q[h]]; i; i = next[i])
        if (flow[i ^ 1] && to[i] != S && dis[to[i]] > dis[q[h]] + 1)
          dis[q[++t] = to[i]] = dis[q[h]] + 1;
  }

  int dfs(int t, int Lim) {
    if (t == T)
      return Lim;
    int ret = 0, p;
    for (; cur[t]; cur[t] = next[cur[t]])
      if (flow[cur[t]] && dis[to[cur[t]]] < dis[t]) {
        p = dfs(to[cur[t]], min(Lim - ret, flow[cur[t]]));
        ret += p;
        flow[cur[t]] -= p, flow[cur[t] ^ 1] += p;
        if (ret == Lim)
          return Lim;
      }
    return ret;
  }

  int dinic() {
    int ret = 0, p = 1;
    bfs();
    memcpy(cur, head, sizeof cur);
    while (p) {
      p = dfs(S, inf);
      ret += p;
    }
    ans += ret;
    return ret;
  }

  void work() {
    while (dinic())
      ;
    // printf("%d\n", ans);
  }
} G;

struct Edge {
  int u, v, f;
};

int n, m;
int x[M], y[M], z[M];

const int E = 1001;

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d%d%d", &n, &m, &G.S, &G.T);
    G.init();
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d%d", &x[i], &y[i], &z[i]);
      G.add(x[i], y[i], z[i] * E + 1);
    }
    G.work();
    printf("%d\n", G.ans % E);
    // printf("    %d\n", siz);
  }

  return 0;
}
