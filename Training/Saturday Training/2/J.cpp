#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 100010, M = N * 2, S = 18;
struct lr {
  int siz, ls, rs;
} T[N * 64];

int tot, head[N], next[M], to[M];
int f[N][S], dep[N], tsiz, a[N];
int root[N], n, m;

void add(int x, int y) {
  to[++tot] = y;
  next[tot] = head[x];
  head[x] = tot;
}

int Modify(int from, int x, int dep) {
  int t = ++tsiz;
  T[t] = T[from];
  T[t].siz++;
  if (dep == 0)
    return t;
  if ((1 << dep - 1) & x) {
    // printf("%d ", 1 << dep - 1);
    T[t].rs = Modify(T[from].rs, x, dep - 1);
  } else {
    T[t].ls = Modify(T[from].ls, x, dep - 1);
    // printf("%d ", 1 << dep - 1);
  }
  return t;
}

void dfs(int t) {
  // printf("%d:\n", a[t]);
  root[t] = Modify(root[f[t][0]], a[t], S);
  // puts("");
  for (int i = head[t]; i; i = next[i])
    if (to[i] != f[t][0]) {
      f[to[i]][0] = t;
      dep[to[i]] = dep[t] + 1;
      dfs(to[i]);
    }
}

void init() {
  memset(f, 0, sizeof f);
  memset(head, 0, sizeof head);
  tsiz = tot = 0;
}

int lca(int x, int y) {
  if (dep[x] < dep[y])
    std::swap(x, y);
  int delta = dep[x] - dep[y];
  for (int j = 0; j <= 17; ++j)
    if ((1 << j) & delta)
      x = f[x][j];
  if (x == y)
    return x;
  for (int j = 17; j >= 0; --j)
    if (f[x][j] != f[y][j])
      x = f[x][j], y = f[y][j];
  return f[x][0];
}

void query(int now, int pre, int x, int dep, int &ans) {
  if (dep == 0) {
    ans = 0;
    return;
  }
  if ((1 << dep - 1) & x) {
    // printf("%d %d %d ", 1 << dep - 1, T[T[now].ls].siz, T[T[now].ls].siz);
    if (T[T[now].ls].siz - T[T[pre].ls].siz > 0) {
      query(T[now].ls, T[pre].ls, x, dep - 1, ans);
      ans += 1 << dep - 1;
    } else {
      query(T[now].rs, T[pre].rs, x, dep - 1, ans);
    }
  } else {
    // printf("%d %d %d ", 1 << dep - 1, T[T[now].rs].siz, T[T[now].rs].siz);
    if (T[T[now].rs].siz - T[T[pre].rs].siz > 0) {
      query(T[now].rs, T[pre].rs, x, dep - 1, ans);
      ans += 1 << dep - 1;
    } else {
      query(T[now].ls, T[pre].ls, x, dep - 1, ans);
    }
  }
}

int main() {
  while (~scanf("%d%d", &n, &m)) {
    init();
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    for (int i = 1, x, y; i < n; ++i) {
      scanf("%d%d", &x, &y);
      add(x, y);
      add(y, x);
    }
    root[0] = 0;
    dfs(1);
    for (int j = 1; j <= 17; ++j)
      for (int i = 1; i <= n; ++i)
        f[i][j] = f[f[i][j - 1]][j - 1];
    for (int i = 1, u, v, x; i <= m; ++i) {
      scanf("%d%d%d", &u, &v, &x);
      int pre = f[lca(u, v)][0], v1, v2;
      // printf("Lca is : %d ", lca(u, v));
      query(root[v], root[pre], x, S, v1);
      query(root[u], root[pre], x, S, v2);
      printf("%d\n", std::max(v1, v2));
    }
  }
  return 0;
}
