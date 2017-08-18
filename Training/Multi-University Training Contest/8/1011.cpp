#include <bits/stdc++.h>

const int N = 2010, mod = 1000000007;
typedef long long LL;
LL c[N][N], n, m, p[N][N], f[N];

LL Pow(LL a, LL n) {
  if (n == 0)
    return 1;
  LL t = Pow(a, n >> 1);
  return n & 1 ? t * t % mod * a % mod : t * t % mod;
}

int main() {
  int Tc;
  c[0][0] = 1;
  for (int i = 1; i <= 2000; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    p[i][0] = 1;
    for (int j = 1; j <= 2000; ++j)
      p[i][j] = p[i][j - 1] * i % mod;
  }
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%lld%lld", &n, &m);
    LL ans = 0, ret;
    f[1] = 1;
    for (int i = 2; i <= m; ++i) {
      f[i] = p[i][n];
      for (int k = 1; k < i; ++k) {
        f[i] = f[i] - c[i][k] * f[k] % mod;
        if (f[i] < 0)
          f[i] += mod;
      }
    }
    for (int t = 1; t <= m; ++t)
      for (int k = 1; k + t <= m; ++k) {
        ret = (c[m][k] * c[m - k][t]) % mod * f[k] % mod * f[t] % mod;
        //* (p[t][n] - c[k][k - 1] * p[t - 1][n] % mod + mod) % mod;
        // if(t != k) ret = ret * 2 % mod;
        ans = (ans + ret) % mod;
      }
    printf("%lld\n", ans);
  }

  return 0;
}
