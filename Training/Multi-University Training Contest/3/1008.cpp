#include <cstdio>
#include <cstring>

typedef unsigned long long LL;
const LL Mod = 1000000007;

LL Pow(LL x, LL n) {
  if (n == 0)
    return 1LL;
  LL t = Pow(x, n >> 1);
  return n & 1 ? t * t % Mod * x % Mod : t * t % Mod;
}
LL n, k;

int main() {
  int Tc = 0;
  while (~scanf("%llu%llu", &n, &k)) {
    ++Tc;
    printf("Case #%d: %llu\n", Tc, Pow(n % Mod, k));
  }
  return 0;
}
