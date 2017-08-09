#include <algorithm>
#include <cstdio>

using std::sort;
int Tc, n, a[100010], k;
int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    int ret = 1, i = n;
    while (i > 1 && a[i] - a[i - 1] <= k)
      --i, ++ret;
    printf("%d\n", ret);
  }
  return 0;
}
