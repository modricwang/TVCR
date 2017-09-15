#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 20000;
const int M = 200;
int times;
int n;
int a[N + 10];
ll sum[N + 10];
ll dp[M + 10][M + 10];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &times);
  for (int T = 1; T <= times; T++) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];

    memset(dp, 0, sizeof(dp));
    for (int i = n; i >= 1; i--) {
      int bound = (int)ceil(sqrt(i * 2 + 10));
      for (int j = 1; j <= bound; j++) {
        if (i + j - 1 > n) {
          dp[i % M][j] = 0;
          continue;
        }
        dp[i % M][j] = sum[i + j - 1] - sum[i - 1] - dp[(i + j) % M][j];
        if (i + j <= n)
          dp[i % M][j] = max(dp[i % M][j], sum[i + j] - sum[i - 1] -
                                               dp[(i + j + 1) % M][j + 1]);
      }
    }

    ll ans = dp[1][1];
    printf("%lld\n", ans);
  }
  return 0;
}
