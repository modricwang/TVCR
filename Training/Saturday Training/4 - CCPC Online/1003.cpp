#include <bits/stdc++.h>

using namespace std;

const int N = 3003;

int fa[N], n;
bool vis[N], flag, e[N][N];

void init() {
  memset(vis, 0, sizeof vis);
  memset(fa, 0, sizeof fa);
}

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

void dfs(int t) {
  vis[t] = 1;
  for (int u = 1; u <= n; ++u) {
    if (t == u || !e[t][u])
      continue;
    if (!vis[u]) {
      fa[u] = t;
      dfs(u);
    } else {
      if (u == fa[fa[t]] || (fa[u] == fa[t] && fa[t] != 0)) {
        flag = 1;
        return;
      }
      fa[u] = t;
    }
  }
}

void ddfs(int t) {
  vis[t] = 1;
  for (int u = 1; u <= n; ++u) {
    if (t == u || e[t][u])
      continue;
    if (!vis[u]) {
      fa[u] = t;
      ddfs(u);
    } else {
      if (u == fa[fa[t]] || (fa[u] == fa[t] && fa[t] != 0)) {
        flag = 1;
        return;
      }
      fa[u] = t;
    }
  }
}

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &n);
    init();
    flag = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 1, x; j + i <= n; ++j) {
        x = F();
        e[i][i + j] = e[i + j][i] = x;
      }
    for (int i = 1; i <= n; ++i) {
      if (!vis[i])
        dfs(i);
      if (flag)
        break;
    }
    if (flag) {
      puts("Bad Team!");
      continue;
    }
    init();
    for (int i = 1; i <= n; ++i) {
      if (!vis[i])
        ddfs(i);
      if (flag)
        break;
    }
    flag ? puts("Bad Team!") : puts("Great Team!");
  }
  return 0;
