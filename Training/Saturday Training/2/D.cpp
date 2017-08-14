#include <cstdio>
#include <cstring>

const int N = 110;

int Tc;

int n, a[N][N], e[N][N], col[N];
bool vis[N];

bool dfs(int t, int f) {
  vis[t] = 1;
  for (int i = 1; i <= n; ++i)
    if (i != t && i != f && e[t][i]) {
      if (!vis[i]) {
        col[i] = col[t] ^ 1;
        if (!dfs(i, t))
          return 0;
      } else {
        if (col[i] == col[t])
          return 0;
      }
    }
  return 1;
}

int main() {
  while (~scanf("%d", &n)) {
    memset(e, 0, sizeof(e));
    memset(a, 0, sizeof(a));
    for (int i = 1, x; i <= n; ++i) {
      while (scanf("%d", &x) && x) {
        a[i][x] = 1;
      }
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (i != j && (!a[i][j] || !a[j][i]))
          e[i][j] = e[j][i] = 1;
    memset(col, 0, sizeof col);
    memset(vis, 0, sizeof vis);
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        flag &= dfs(i, 0);
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
