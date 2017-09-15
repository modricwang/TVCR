#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using std::max;
using std::min;
typedef long long LL;
const int N = 100010, M = N << 1;

int Tc, ans, tot, sell[N], buy[N];
;
int a[N], n, head[N], next[M], to[M], c[M];

void init() {
  ans = tot = 0;
  clear(head);
}

void dfs(int t, int fa) {
  sell[t] = buy[t] = a[t];
  for (int i = head[t]; i; i = next[i]) {
    if (to[i] == fa)
      continue;
    dfs(to[i], t);
    sell[t] = max(sell[to[i]] - c[i], sell[t]);
    buy[t] = min(buy[to[i]] + c[i], buy[t]);
  }
  ans = max(ans, sell[t] - buy[t]);
}

void add(int x, int y, int z) {
  to[++tot] = y;
  next[tot] = head[x];
  head[x] = tot;
  c[tot] = z;
}

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &n);
    init();
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    for (int i = 1, x, y, z; i < n; ++i) {
      scanf("%d%d%d", &x, &y, &z);
      add(x, y, z), add(y, x, z);
    }
    dfs(1, 0);
    printf("%d\n", ans);
  }
  return 0;
}
