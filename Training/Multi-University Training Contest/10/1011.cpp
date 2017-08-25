#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

const long long MAXN = 100000LL + 7;
const long long INF = 1000000000000000LL;
using namespace std;

struct edge {
  long long to, cost;

  edge(long long tv = 0, long long tc = 0) : to(tv), cost(tc) {}
};

typedef pair<long long, long long> P;
int N, R;
vector<edge> graph[MAXN];
long long dist[MAXN];  //最短距离
long long dist2[MAXN]; //次短距离

void solve() {
  fill(dist, dist + N, INF);
  fill(dist2, dist2 + N, INF);
  //从小到大的优先队列
  //使用pair而不用edge结构体
  //是因为这样我们不需要重载运算符
  // pair是以first为主关键字进行排序
  priority_queue<P, vector<P>, greater<P>> Q;
  //初始化源点信息
  dist[0] = 0;
  Q.push(P(0, 0));
  //同时求解最短路和次短路
  while (!Q.empty()) {
    P p = Q.top();
    Q.pop();
    // first为s->to的距离，second为edge结构体的to
    long long v = p.second, d = p.first;
    //当取出的值不是当前最短距离或次短距离，就舍弃他
    if (dist2[v] < d)
      continue;
    for (unsigned i = 0; i < graph[v].size(); i++) {
      edge &e = graph[v][i];
      long long d2 = d + e.cost;
      if (dist[e.to] > d2) {
        swap(dist[e.to], d2);
        Q.push(P(dist[e.to], e.to));
      }
      if (dist2[e.to] > d2 && dist[v] < d2) {
        dist2[e.to] = d2;
        Q.push(P(dist2[e.to], e.to));
      }
    }
  }
  // printf("%d\n", dist2[N - 1]);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < MAXN; i++)
      graph[i].clear();
    int n, m;
    cin >> n >> m;
    N = n;
    long long f, t, w;
    for (int i = 0; i < m; i++) {
      cin >> f >> t >> w;
      graph[f - 1].push_back(edge(t - 1, w));
      graph[t - 1].push_back(edge(f - 1, w));
    }
    solve();
    printf("%lld\n", dist2[n - 1]);
  }
}
