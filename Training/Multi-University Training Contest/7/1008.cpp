#include <bits/stdc++.h>

const int N = 50010;
const double pi = acos(-1.0);
typedef long long LL;
struct lr {
  double x, y;
  LL v;
  double rad;
  bool operator<(const lr &a) const { return rad < a.rad; }
} a[N];
int n;

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &n);
    LL sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lf%lf%lld", &a[i].x, &a[i].y, &a[i].v);
      sum1 += a[i].v;
      a[i].rad = std::atan2(a[i].y, a[i].x);
      if (a[i].rad < 0)
        a[i].rad += pi;
    }
    LL ans = 0, add = 0;
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
      if (a[i].y >= 0) {
        sum1 -= a[i].v;
        sum2 += a[i].v;
      }
    ans = sum1 * sum2;
    for (int i = 1; i <= n; ++i) {
      if (a[i].y >= 0) {
        sum1 += a[i].v;
        sum2 -= a[i].v;
      } else {
        sum2 += a[i].v;
        sum1 -= a[i].v;
      }
      if (sum1 * sum2 > ans)
        ans = sum1 * sum2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
