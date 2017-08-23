#include <bits/stdc++.h>
#define inf 4444444444444444LL
using std::multiset;
typedef long long LL;
const int N = 100005 * 4, M = N;

struct lr {
  int x;
  LL dis;
  bool operator<(const lr &a) const { return dis < a.dis; }
} t, dis[2][N];

multiset<lr> info;
multiset<lr>::iterator it;

int head[N], next[M], to[M], tot, q[M * 10];
int n, m, ans, S, c[M];
bool vis[N], Set[N];
LL e[N][3];

void add(LL x, LL y, LL z) {
  to[++tot] = y;
  next[tot] = head[x];
  head[x] = tot;
  c[tot] = z;
}

void init() {
  tot = 0;
  memset(vis, 0, sizeof vis);
  memset(Set, 0, sizeof Set);
  memset(head, 0, sizeof head);
  dis[0][0] = (lr){0, inf};
  for (int i = 1; i <= n + n; ++i) {
    dis[1][i] = dis[0][i] = dis[0][0];
  }
}

void spfa(int t) {
  for (int h = 1; h <= t; ++h) {
    // if(h > LIM) for(;;);
    for (int i = head[q[h]]; i; i = next[i]) {
      bool flag = 0;
      if (dis[0][to[i]].dis > dis[0][q[h]].dis + c[i]) {
        if (dis[1][to[i]].x != dis[0][to[i]].x)
          dis[1][to[i]] = dis[0][to[i]];
        dis[0][to[i]] = (lr){dis[0][q[h]].x, dis[0][q[h]].dis + c[i]};
        flag = 1;
      } else if (dis[0][to[i]].x != dis[0][q[h]].x &&
                 dis[1][to[i]].dis > dis[0][q[h]].dis + c[i]) {
        dis[1][to[i]] = (lr){dis[0][q[h]].x, dis[0][q[h]].dis + c[i]};
        flag = 1;
      } else if (dis[1][q[h]].x != dis[1][to[i]].x &&
                 dis[1][to[i]].dis > dis[1][q[h]].dis + c[i]) {
        dis[1][to[i]] = dis[1][q[h]];
        dis[1][to[i]].dis += c[i];
        flag = 1;
      }
      if (flag)
        vis[q[++t] = to[i]] = 1;
    }
    vis[q[h]] = 0;
  }
}

int main() {
  int Tc, K;
  scanf("%d", &Tc);
  for (int tc = 1; tc <= Tc; ++tc) {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m; ++i) {
      scanf("%lld%lld%lld", e[i] + 0, e[i] + 1, e[i] + 2);
    }
    scanf("%d", &K);
    for (int i = 1, x; i <= K; ++i) {
      scanf("%d", &x);
      Set[x] = 1;
      dis[0][x + n] = (lr){x, 0};
      dis[1][x + n] = (lr){x, inf};
      vis[q[i] = x + n] = 1;
    }
    for (int i = 1, u, v, z; i <= m; ++i) {
      u = e[i][0], v = e[i][1], z = e[i][2];
      if (u == v)
        continue;
      if (Set[u])
        u += n;
      add(u, v, z);
    }
    // dijkstra(S);
    spfa(K);
    LL ans = inf;
    for (int i = 1; i <= n; ++i)
      if (Set[i]) {
        if (dis[0][i].x != i && dis[0][i].dis < ans)
          ans = dis[0][i].dis;
        if (dis[1][i].x != i && dis[1][i].dis < ans)
          ans = dis[1][i].dis;
      }
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}
