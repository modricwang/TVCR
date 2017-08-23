#include <bits/stdc++.h>

const int N = 1010, M = 6010;

struct Graph {
  int to[M], next[M], head[N], tot, Time, scc;
  int s[N], top, dfn[N], low[N], belong[N];
  void init() {
    tot = Time = 0;
    memset(head, 0, sizeof head);
    memset(belong, 0, sizeof belong);
    memset(dfn, 0, sizeof dfn);
    scc = top = 0;
  }
  inline void Min(int &a, const int &b) {
    if (b < a)
      a = b;
  }
  void add(int x, int y) {
    to[++tot] = y;
    next[tot] = head[x];
    head[x] = tot;
  }
  void dfs(int t) {
    dfn[s[++top] = t] = low[t] = ++Time;
    for (int i = head[t]; i; i = next[i])
      if (!dfn[to[i]]) {
        dfs(to[i]);
        Min(low[t], low[to[i]]);
      } else if (!belong[to[i]])
        Min(low[t], dfn[to[i]]);
    if (low[t] == dfn[t]) {
      int v;
      ++scc;
      do {
        v = s[top--];
        belong[v] = scc;
      } while (v != t);
    }
  }
} G, T;
int n, m, e[M][2], dep[N];

void Max(int &a, int b) {
  if (b > a)
    a = b;
}

void get(int t) {
  dep[t] = 1;
  for (int i = T.head[t]; i; i = T.next[i]) {
    if (!dep[T.to[i]]) {
      get(T.to[i]);
    }
    Max(dep[t], dep[T.to[i]] + 1);
  }
}

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d", &n, &m);
    G.init();
    for (int i = 1, x, y; i <= m; ++i) {
      scanf("%d%d", &x, &y);
      G.add(x, y);
      e[i][0] = x, e[i][1] = y;
    }
    for (int i = 1; i <= n; ++i)
      if (!G.belong[i])
        G.dfs(i);
    T.init();
    for (int i = 1; i <= m; ++i) {
      if (G.belong[e[i][0]] != G.belong[e[i][1]]) {
        T.add(G.belong[e[i][0]], G.belong[e[i][1]]);
      }
    }
    bool flag = 1;
    memset(dep, 0, sizeof(dep));
    // printf("    %d\n ", G.scc);
    for (int i = 1; i <= G.scc; ++i)
      if (!dep[i]) {
        get(i);
        if (dep[i] == G.scc)
          flag = 0;
      }
    flag ? puts("Light my fire!")
         : puts("I love you my love and our love save us!");
  }
  return 0;
}
