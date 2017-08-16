#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL inf = 1000000000000000000LL;
typedef pair<LL, LL> PLL;
const int N = 100;

long long calc(long long n) {
  long long t = n & 3;
  if (t & 1)
    return t / 2u ^ 1;
  return t / 2u ^ n;
}

LL n, siz[N], Left[N];
int main() {
  int Tc, dep;
  LL sum, ans, n, k;
  for (scanf("%d", &Tc); Tc--;) {
    sum = ans = dep = 0;
    scanf("%lld%lld", &n, &k);
    if (k == 1) {
      printf("%lld\n", calc(n));
      continue;
    }
    sum = siz[0] = 1;
    while (sum < n) {
      siz[++dep] = 0;
      if (inf / k >= siz[dep - 1])
        siz[dep] = siz[dep - 1] * k;
      else
        break;
      sum += siz[dep];
    }
    sum -= siz[dep];
    Left[dep] = siz[dep] = n - sum;
    if (siz[dep] & 1)
      ans = 1;
    //            printf(" siz    %lld\n", siz[dep]);

    LL SK = 1, NK, SPE = 0;
    LL now = n - 1;
    for (int i = dep - 1; i >= 0; --i) {

      NK = SK * k + 1;
      sum -= siz[i];

      now = (now - 1) / k; // -1

      Left[i] = now - sum;
      if (Left[i] & 1)
        ans ^= NK;
      if ((siz[i] - Left[i] - 1) & 1)
        ans ^= SK;
      // printf("    SK NK LEFT %lld %lld %lld %lld %lld\n", sum, now, SK, NK,
      // siz[i] - Left[i] - 1);  printf("%lld\n", ans);
      LL tmp = Left[i + 1] - Left[i] * k;
      SPE += tmp * SK + (SK - 1) / k * (k - tmp - 1) + 1;
      // printf("    SPE %lld\n", SPE);
      ans ^= SPE;

      SK = NK;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
