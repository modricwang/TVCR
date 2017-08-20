#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const ll K = 36;
const ll N = 100;
const ll INF = 0x3f3f3f3f3f3f3f3f;
// ll times;
ll p[N + 10][N + 10];

ll bit[N + 10];
ll l;

ll calc(ll x, ll k) {
  l = 0;
  for (ll i = x; i >= 1; i /= k)
    bit[++l] = i % k;
  if (l == 0)
    return 0;

  ll ans = 0;
  for (ll i = 1; i < l; i++) {
    ll tmp = (i + 1) / 2;
    ans += p[k][tmp - 1] * (k - 1);
  }

  ll l2 = 0, L1 = 0, L2 = 0, R1 = 0, R2 = 0;
  for (ll i = 1, j = l; i <= j; i++, j--) {
    L1 = L1 * k + bit[i];
    R1 = R1 * k + bit[j];
    L2 = L2 + bit[i] * p[k][l2];
    R2 = R2 + bit[j] * p[k][l2];
    l2++;
  }

  ll upper = R1;
  ll lower = p[k][l2 - 1];

  ans += upper - lower + (R2 <= L2 ? 1 : 0);

  // printf("x:%lld k:%lld ans:%lld\n", x, k, ans);
  return ans * (k - 1) + x;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  for (ll i = 2; i <= K; i++) {
    p[i][0] = 1;
    for (ll j = 1; p[i][j - 1] <= INF / i; j++)
      p[i][j] = p[i][j - 1] * i;
  }

  ll times;
  scanf("%lld", &times);
  ll L, R, l, r;
  for (ll T = 1; T <= times; T++) {
    scanf("%lld%lld%lld%lld", &L, &R, &l, &r);

    ll ans = 0;
    for (ll i = l; i <= r; i++) {
      // ans += (calc(R, i) - calc(L - 1, i)) * i;
      ans += calc(R, i) - calc(L - 1, i);
    }

    printf("Case #%lld: %lld\n", T, ans);
  }
  return 0;
}
