#include <bits/stdc++.h>

typedef long long LL;
const int N = 1000;
int Tc, n, a[N], len, m;

int gcd(int a, int b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

void mul(int t) {
  for (int i = 0; i < len; ++i)
    a[i] *= t;
  for (int i = 0; i < len; ++i) {
    a[i + 1] += a[i] / 10;
    a[i] %= 10;
  }
  while (a[len])
    ++len;
}

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d", &m, &n);
    int u = n, v, t;
    memset(a, 0, sizeof(a));
    len = a[0] = 1;
    for (int i = 1; i < n; ++i) {
      v = m;
      t = gcd(v, u);
      v /= t;
      u /= t;
      mul(v);
    }
    printf("%d/", u);
    for (int i = len - 1; i >= 0; --i)
      printf("%d", a[i]);
    puts("");
  }
  return 0;
}
