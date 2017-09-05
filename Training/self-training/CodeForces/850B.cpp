#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

const ll A = 1000000 * 2;
ll n, x, y;
ll l;
ll a[A + 10];
ll s[A + 10], sum[A + 10];

bool valid[A + 10];
ll prime[A + 10];
ll tot;

void init_prime() {
  memset(valid, true, sizeof(valid));

  for (int i = 2; i <= A; i++) {
    if (valid[i])
      prime[++tot] = i;

    for (int j = 1; j <= tot && i * prime[j] <= A; j++) {
      valid[i * prime[j]] = false;
      if (i % prime[j] == 0)
        break;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  init_prime();

  scanf("%lld%lld%lld", &n, &x, &y);
  l = x / y;
  for (ll i = 1; i <= n; i++) {
    ll x;
    scanf("%lld", &x);
    a[x]++;
  }

  for (ll i = 1; i <= A; i++) {
    s[i] = s[i - 1] + a[i];
    sum[i] = sum[i - 1] + a[i] * i;
  }

  ll ans = (long long)1e18;
  for (ll i = 1; i <= tot; i++) {
    ll k = prime[i];
    ll tmp = 0;

    for (ll j = 0; j <= A; j += k) {
      ll mid = max(j + k - l - 1, j);
      ll bound = min(j + k - 1, A);

      if (bound > mid) {
        tmp += ((s[bound] - s[mid]) * (j + k) - (sum[bound] - sum[mid])) * y;
        tmp += (s[mid] - s[j]) * x;
      } else {
        tmp += (s[bound] - s[j]) * x;
      }
    }

    ans = min(ans, tmp);
  }

  printf("%lld\n", ans);

  return 0;
}
