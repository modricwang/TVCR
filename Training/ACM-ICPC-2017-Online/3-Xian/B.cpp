#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const LL mod = 1000000007;

struct Matrix {
  LL x, y, M[3][3];
  void init() {
    x = y = 0;
    clear(M);
  }
} a, t;

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix c;
  c.init();
  c.x = a.x;
  c.y = b.y;
  for (register int i = 0; i < a.x; ++i)
    for (register int j = 0; j < b.y; ++j)
      for (register int k = 0; k < a.y; ++k)
        c.M[i][j] = (c.M[i][j] + a.M[i][k] * b.M[k][j]) % mod;
  return c;
}

void Pow(Matrix &a, int n) { // pow a ^ (n + 1)
  register Matrix t = a;
  for (; n; n >>= 1) {
    if (n & 1)
      a = a * t;
    t = t * t;
  }
}

LL exgcd(LL a, LL b, LL c) {
  a %= b, c %= b;
  if (!c)
    return 0;
  return (exgcd(b, a, a * b - c) * b + c) / a;
}

int main() {
  int Tc;
  LL p, q, k;
  scanf("%d", &Tc);
  while (Tc--) {
    scanf("%lld%lld%lld", &p, &q, &k);
    LL Inv = exgcd(p, mod, 1);
    a.init();
    t.init();
    a.x = 1, a.y = 2;
    t.x = t.y = 2;

    t.M[0][0] = t.M[1][1] = (p - q) * Inv % mod;
    t.M[1][0] = t.M[0][1] = q * Inv % mod;
    // printf("%lld %lld \n%lld %lld\n\n", t.M[0][0], t.M[0][1], t.M[1][0],
    // t.M[1][1]);

    a.M[0][0] = 1, a.M[0][1] = 0;
    // t = t * t;
    Pow(t, k - 1);
    // printf("%lld %lld \n%lld %lld\n", t.M[0][0], t.M[0][1], t.M[1][0],
    // t.M[1][1]);
    a = a * t;
    printf("%lld\n", a.M[0][0]);
  }
  return 0;
}
