#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int N = 100010, mod = 998244353;

LL exgcd(LL a, LL b, LL c) {
  a %= b, c %= b;
  if (!c)
    return 0;
  return (exgcd(b, a, a * b - c) * b + c) / a;
}

int n, m;
LL Ca[N], Cb[N];

int main() {
  while (~scanf("%d%d", &n, &m)) {
    if ((m + n) & 1) {
      puts("0");
      continue;
    }
    if (m > n) {
      puts("0");
      continue;
    }

    Ca[0] = 1;
    for (int i = 1; i <= m; ++i) {
      Ca[i] = Ca[i - 1] * (n - i + 1) % mod * exgcd(i, mod, 1) % mod;
    }
    int t = (n - m) / 2;

    Cb[0] = 1; // Cb--->i + t
    for (int i = t + 1; i + i <= n; ++i) {
      int now = i - t;
      Cb[now] = Cb[now - 1] * i % mod * exgcd(i - t, mod, 1) % mod;
    }
    LL ans = 0;
    /*
    for(int i = 0; i <= m + 1; ++i) printf("%lld ", Ca[i]);
    puts("");
    for(int i = 0; i <= m + 1; ++i) printf("%lld ", Cb[i]);
    puts("");
    */
    for (int k = t; k + k <= n; ++k) {
      ans = (ans + Ca[n - k - k] * Cb[k - t]) % mod;
    }
    if (t & 1)
      ans = mod - ans;
    printf("%lld\n", ans);
  }
  return 0;
}
