#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int N = 100010;

LL a[30] = {
    0,
    1,
    8,
    49,
    288,
    1681,
    9800,
    57121,
    332928,
    1940449,
    11309768,
    65918161,
    384199200,
    2239277041,
    13051463048,
    76069501249,
    443365544448,
    2584123765441,
    15061377048200,
    87784138523761,
    511643454094368,
    2982076586042449,
    17380816062160328,
    101302819786919521,
    590436102659356800,
};
LL n;

int main() {
  int Tc;
  scanf("%d", &Tc);
  for (int tc = 1; tc <= Tc; ++tc) {
    scanf("%lld", &n);
    for (int i = 1; i <= 25; ++i)
      if (a[i] >= n) {
        printf("Case #%d: %lld\n", tc, a[i]);
        break;
      }
  }
  return 0;
}
