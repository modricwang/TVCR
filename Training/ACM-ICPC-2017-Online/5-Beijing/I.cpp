#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clr(x) memset(x, 0, sizeof x)

const int inf = 2100000000;

using namespace std;
typedef long long LL;
const int N = (1 << 17) + 10;

int Tc, n, k;
struct Node {
  int Mx, Mn, mx, mn; // Mx Mn >= 0
  void init() {
    Mx = mx = -1;
    Mn = mn = 2100000000;
  }
  void Do(int v) {
    init();
    if (v >= 0) {
      Mx = max(Mx, v);
      Mn = min(Mn, v);
    } else {
      v = -v;
      mx = max(mx, v);
      mn = min(mn, v);
    }
  }
} T[N * 4];

int a[N];

void update(int t) {
  int Ls = t << 1, Rs = Ls | 1;
  T[t].mx = max(T[Ls].mx, T[Rs].mx);
  T[t].mn = min(T[Ls].mn, T[Rs].mn);
  T[t].Mx = max(T[Ls].Mx, T[Rs].Mx);
  T[t].Mn = min(T[Ls].Mn, T[Rs].Mn);
}

void build(int t, int l, int r) {
  if (l == r) {
    T[t].Do(a[l]);
    return;
  }
  int mid = l + r >> 1;
  build(t << 1, l, mid);
  build(t << 1 | 1, mid + 1, r);
  update(t);
}

void modify(int t, int l, int r, int x, int v) {
  if (l == r) {
    T[t].Do(v);
    return;
  }
  int mid = l + r >> 1, Ls = t << 1;
  if (x <= mid)
    modify(Ls, l, mid, x, v);
  else
    modify(Ls | 1, mid + 1, r, x, v);
  update(t);
}

Node query(int t, int l, int r, int x, int y) {
  if (x <= l && r <= y)
    return T[t];
  int mid = l + r >> 1, Ls = t << 1;
  Node ret, Tmp;
  ret.init();
  if (x <= mid) {
    Tmp = query(Ls, l, mid, x, y);
    ret.mx = max(ret.mx, Tmp.mx);
    ret.Mx = max(ret.Mx, Tmp.Mx);
    ret.mn = min(ret.mn, Tmp.mn);
    ret.Mn = min(ret.Mn, Tmp.Mn);
  }
  if (y > mid) {
    Tmp = query(Ls | 1, mid + 1, r, x, y);
    ret.mx = max(ret.mx, Tmp.mx);
    ret.Mx = max(ret.Mx, Tmp.Mx);
    ret.mn = min(ret.mn, Tmp.mn);
    ret.Mn = min(ret.Mn, Tmp.Mn);
  }
  return ret;
}

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &k);
    INF(T);
    n = 1 << k;
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    build(1, 1, n);
    int Qc, ty, l, r;
    for (scanf("%d", &Qc); Qc--;) {
      scanf("%d%d%d", &ty, &l, &r);
      if (ty == 1) {
        Node t = query(1, 1, n, l + 1, r + 1);
        LL ans = 1LL << 50;
        if (t.Mx >= 0 && t.mx >= 0)
          ans = min(ans, (LL)-t.mx * t.Mx);
        ans = min(ans, (LL)t.mn * t.mn);
        ans = min(ans, (LL)t.Mn * t.Mn);
        printf("%lld\n", ans);
      } else {
        modify(1, 1, n, l + 1, r);
      }
    }
  }
  return 0;
}
