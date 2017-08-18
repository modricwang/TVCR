#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1000;
const int M = 1000000;
int times;
int n, m;
int a[N + 10];
char b[N + 10][2];

int l[N + 10], r[N + 10];

bool dp[2][M * 2 + 10];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int times;
  scanf("%d", &times);
  for (int T = 1; T <= times; T++) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
      scanf("%s", b[i]);

    l[n + 1] = M + m;
    r[n + 1] = M + m;
    for (int i = n; i >= 1; i--) {
      if (b[i][0] == 'L')
        l[i] = l[i + 1] - a[i], r[i] = r[i + 1];
      else if (b[i][0] == 'D')
        l[i] = l[i + 1], r[i] = r[i + 1] + a[i];
      else if (b[i][0] == 'N')
        l[i] = l[i + 1] - a[i], r[i] = r[i + 1] + a[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][M] = true;
    int L = M, R = M;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      int s = max(L, l[i]), t = min(R, r[i]);
      if (s > t) {
        flag = false;
        break;
      }

      int last = (i - 1) % 2, now = i % 2;
      for (int j = s; j <= t; j++)
        if (dp[last][j]) {
          dp[now][j] = true;
          if (b[i][0] == 'L' || b[i][0] == 'N')
            dp[now][j + a[i]] = true;
          if (b[i][0] == 'D' || b[i][0] == 'N')
            dp[now][j - a[i]] = true;
        }

      if (b[i][0] == 'L' || b[i][0] == 'N')
        R += a[i];
      if (b[i][0] == 'D' || b[i][0] == 'N')
        L -= a[i];
    }

    bool ans = dp[n % 2][M + m];
    printf(flag && ans ? "yes\n" : "no\n");
  }
  return 0;
}
