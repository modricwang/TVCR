#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
typedef long long ll;

int times;
ll x;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &times);
  for (int T = 1; T <= times; T++) {
    scanf("%lld", &x);
    if (x == 1) {
      printf("%lld\n", 4ll);
      continue;
    }

    ll n = (ll)ceil(sqrt(x / 2.0));

    ll ans = 0;
    if (x <= (n - 1) * (n - 1) * 2 + n - 2)
      ans = n * 4 - 3;
    else if (x <= n * (n - 1) * 2)
      ans = n * 4 - 2;
    else if (x <= n * (n - 1) * 2 + n - 1)
      ans = n * 4 - 1;
    else if (x <= n * n * 2)
      ans = n * 4;

    printf("%lld\n", ans);
  }
  return 0;
}
