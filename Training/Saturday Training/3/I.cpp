#include <bits/stdc++.h>

const int Mod = 95041567;
typedef long long LL;
const int m[7] = {0, 31, 37, 41, 43, 47};

LL B[52], r[7], c[52][52];
int Tc, n;

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  LL r = ex_gcd(b, a % b, y, x);
  y -= x * (a / b);
  return r;
}

LL CRT(LL a[], int n) {
  LL ret = 0, x, y, tm;
  for (int i = 1; i <= n; ++i) {
    tm = Mod / m[i];
    ex_gcd(tm, m[i], x, y);
    ret = (ret + tm * x * a[i]) % Mod;
  }
  return (ret + Mod) % Mod;
}

struct Matrix {
  int x, y;
  int v[50][50];
  Matrix() { memset(v, 0, sizeof(v)); }
  Matrix(int tx, int ty) : x(tx), y(ty) { memset(v, 0, sizeof(v)); }
} E;

void init() {
  for (int i = 0; i < 50; ++i)
    E.v[i][i] = 1;
  B[0] = B[1] = 1;
  B[2] = 2;
  c[0][0] = 1;
  for (int i = 1; i <= 50; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
  }
  for (int i = 2; i <= 50; ++i) {
    for (int j = 0; j <= i; ++j)
      B[i + 1] = (B[i + 1] + c[i][j] * B[j]) % Mod;
    //	printf("%lld ", B[i + 1]);
  }
}

void mul(Matrix &c, const Matrix &a, const Matrix &b, int mod) {
  c.x = a.x, c.y = b.y;
  for (int i = 0; i < a.x; ++i)
    for (int j = 0; j < b.y; ++j)
      for (int k = 0; k < a.y; ++k) {
        c.v[i][j] = (c.v[i][j] + a.v[i][k] * b.v[k][j]) % mod;
      }
}

Matrix Pow(const Matrix &a, int n, int mod) {
  // printf("%d nn ", n);
  if (n == 1)
    return a;
  if (!n)
    return E;
  Matrix t = Pow(a, n >> 1, mod), v;
  mul(v, t, t, mod);
  if (n & 1) {
    Matrix u;
    mul(u, v, a, mod);
    return u;
  }
  return v;
}

int cal(Matrix &X, Matrix &A, int n, int mod) {
  A = Pow(A, n, mod);
  Matrix c;
  mul(c, X, A, mod);
  return c.v[0][0];
}

int main() {
  init();
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &n);
    for (int i = 1; i <= 5; ++i) {
      Matrix X(1, m[i]), A(m[i], m[i]);
      for (int j = 0; j < m[i]; ++j) {
        X.v[0][j] = (int)(B[j] % m[i]);
      }
      for (int j = 1; j < m[i]; ++j) {
        A.v[j][j - 1] = 1;
      }
      A.v[0][m[i] - 1] = A.v[1][m[i] - 1] = 1;
      // A.print();
      E.x = E.y = m[i];
      r[i] = (LL)cal(X, A, n, m[i]);
      // printf("	%lld\n", r[i]);
    }
    printf("%lld\n", CRT(r, 5));
  }
  return 0;
}
