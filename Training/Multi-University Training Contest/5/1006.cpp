#include <algorithm>
#include <cstdio>

typedef long long LL;
LL m, ans, n;
int Tc;

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%lld%lld", &n, &m);
    ans = 0;
    if (m < n - 1) {
      ans = m + m * (m - 1);
      LL ret = n - m - 1;
      ans += ret * (ret - 1) / 2 * n + ret * (m + 1) * n;
      ans *= 2;
    } else if (m > n * (n - 1) / 2) {
      ans = n * (n - 1);
    } else {
      ans = n - 1 + (n - 1) * (n - 2);
      ans -= m - n + 1;
      ans *= 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
