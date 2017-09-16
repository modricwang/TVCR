#include <bits/stdc++.h>

#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using std::sqrt;
using std::max;
using std::swap;
using std::min;
typedef long long LL;
const int N = 50010, M = N << 1;

int parent[N][251], f[N][251], fa[N][20], Lim, dep[N];
int to[M], next[M], head[N], tot, m, n;
int a[N];

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

void add(int x, int y) {
  to[++tot] = y;
  next[tot] = head[x];
  head[x] = tot;
}

void dfs(int t) {
  f[t][1] ^= a[t];
  for (int i = 2; i <= Lim; ++i) {
    parent[t][i] = parent[parent[t][i - 1]][1];
    f[t][i] = a[t] ^ f[parent[t][i]][i];
  }
  for (int i = head[t]; i; i = next[i])
    if (to[i] != fa[t][0]) {
      fa[to[i]][0] = parent[to[i]][1] = t;
      f[to[i]][1] = f[t][1];
      dep[to[i]] = dep[t] + 1;
      dfs(to[i]);
    }
}

int Lca(int x, int y) {
  if (dep[x] < dep[y])
    swap(x, y);
  int delta = dep[x] - dep[y];
  for (int j = 19; j >= 0; --j)
    if (delta & (1 << j))
      x = fa[x][j];
  if (x == y)
    return x;
  for (int j = 19; j >= 0; --j)
    if (fa[x][j] != fa[y][j]) {
      x = fa[x][j];
      y = fa[y][j];
    }
  return fa[x][0];
}

inline void jump(int &x, int k) {
  for (int i = 0; i <= 19; ++i)
    if ((1 << i) & k)
      x = fa[x][i];
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    clear(parent);
    clear(f);
    clear(fa);
    clear(dep);
    tot = 0;
    clear(head);
    for (int i = 1, u, v; i < n; ++i) {
      u = F(), v = F();
      add(u, v), add(v, u);
    }
    // Lim = max((int)sqrt(n), min(n, 200));
    Lim = sqrt(n);
    // for(int i = 1
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      parent[i][0] = i;
    }
    dep[1] = 1;
    dfs(1);
    for (int j = 1; j <= 19; ++j)
      for (int i = 1; i <= n; ++i)
        fa[i][j] = fa[fa[i][j - 1]][j - 1];
    while (m--) {
      int u, v, k, lca;
      u = F(), v = F(), k = F();
      lca = Lca(u, v);
      if (k > Lim) {
        int delta = (dep[u] - dep[lca]) % k, ans = 0;
        int dt = (delta + dep[v] - dep[lca]) % k;
        jump(v, dt);
        while (dep[v] > dep[lca]) {
          ans ^= a[v];
          jump(v, k);
        }
        while (dep[u] >= dep[lca]) {
          ans ^= a[u];
          jump(u, k);
        }
        printf("%d\n", ans);
      } else {
        int delta = (dep[u] - dep[lca]) % k, ans = f[u][k];
        ans ^= f[parent[lca][k - delta]][k];

        int dt = (delta + dep[v] - dep[lca]) % k;
        v = parent[v][dt];
        if (dep[v] >= dep[lca]) {
          ans ^= f[v][k];
          delta = (dep[v] - dep[lca]) % k;
          if (delta == 0)
            delta = k;
          ans ^= f[parent[lca][k - delta]][k];
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
