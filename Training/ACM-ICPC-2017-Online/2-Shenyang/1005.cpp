#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int mod = 998244353;
struct Matrix {
  LL x, y, M[3][3];
  void init() { memset(M, 0, 72); }
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

void Pow(Matrix &a, int n) {
  register Matrix t = a;
  for (; n; n >>= 1) {
    if (n & 1)
      a = a * t;
    t = t * t;
  }
}

int k;
int main() {
  while (~scanf("%d", &k)) {
    //(2,3)
    a.x = 1, a.y = 2;
    a.M[0][0] = 1, a.M[0][1] = 2;
    t.x = t.y = 2;
    t.M[0][0] = 0, t.M[0][1] = t.M[1][0] = t.M[1][1] = 1;
    Pow(t, k + k);
    a = a * t;
    printf("%lld\n", (a.M[0][0] - 1 + mod) % mod);
  }
  return 0;
}
