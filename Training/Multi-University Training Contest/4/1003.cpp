#include <cstdio>
#include <cstring>

const int N = 1000010;
int f[N][41], tot;
int siz[N];
const int mod = 998244353;

int p[N + 1];

inline void Pr() {
  for (register int i = 2; i < 1000000; i++) {
    if (!p[i])
      p[++tot] = i;
    for (register int j = 1; j <= tot && p[j] <= 1000000 / i; j++) {
      p[p[j] * i] = 1;
      if (i % p[j] == 0)
        break;
    }
  }
}

typedef long long LL;
LL ans, now, ret;
inline void Add(LL &a, const LL &b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

int main() {
  register LL l, r, t;
  register int len, i, j, cnt;
  register int Tc, k;
  Pr();
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%lld%lld%d", &l, &r, &k);
    memset(siz, 0, sizeof(siz));
    len = (int)(r - l);
    for (i = 1; i <= tot; ++i) {
      if (p[i] * p[i] > r)
        break;
      for (t = (l - 1) / p[i] * p[i] + p[i]; t <= r; t += p[i]) {
        f[t - l][siz[t - l]++] = p[i];
      }
    }
    ans = 0;
    for (i = 0; i <= len; ++i) {
      now = i + l, ret = 1;
      for (j = 0; j < siz[i]; ++j) {
        cnt = 0;
        while (now % f[i][j] == 0) {
          cnt++;
          now /= f[i][j];
        }
        ret = (cnt * k + 1) * ret % mod;
      }
      if (now > 1)
        ret = ret * (k + 1) % mod;
      Add(ans, ret);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
