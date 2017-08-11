#include <bits/stdc++.h>

using namespace std;

int Tc, n, a[10];

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 7; ++j)
        scanf("%d", a + j);
      int tmp = a[1] + a[2] + a[3] - a[4] - a[5] - a[6] + a[7];
      // if(min(a[1], a[2]) <= a[4] || min(a[2], a[3]) <= a[5] ||
      //    min(a[3], a[1]) <= a[6] || tmp <= 0) continue;
      if (a[4] < a[7] || a[5] < a[7] || a[6] < a[7])
        continue;
      // if(tmp - a[1] != a[2] + a[3] - a[4] - a[6] + a[7]) continue;
      // if(tmp - a[2] != a[1] + a[3] - a[4] - a[5] + a[7]) continue;
      // if(tmp - a[3] != a[1] + a[2] - a[5] - a[6] + a[7]) continue;
      if (a[4] + a[6] - a[7] > a[1])
        continue;
      if (a[4] + a[5] - a[7] > a[2])
        continue;
      if (a[6] + a[5] - a[7] > a[3])
        continue;
      ans = max(ans, tmp);
    }
    printf("%d\n", ans);
  }
  return 0;
}
