#include <bits/stdc++.h>

#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int N = 10010, M = 200010;

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

int n, m, in[N], out[N], e[M][2];

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
    // T.init();
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    for (int i = 1; i <= m; ++i) {
      int u = G.belong[e[i][0]], v = G.belong[e[i][1]];
      if (u != v) {
        // T.add(u, v);
        ++in[v];
        ++out[u];
        // u = get(u), v = get(v);
        // if(v != u) f[v] = u;
      }
    }

    int In = 0, Out = 0, Ans = 0;
    for (int i = 1; i <= G.scc; ++i) {
      In += in[i] == 0;
      Out += out[i] == 0;
    }
    // if(In != 1) Ans = In;
    // Ans += Out;
    Ans = max(In, Out);
    if (G.scc == 1)
      puts("0");
    else
      printf("%d\n", Ans);
  }
  return 0;
}
