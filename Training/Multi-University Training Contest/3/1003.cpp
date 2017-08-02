#include <algorithm>
#include <cstdio>
#include <cstring>

const int N = 500010;
int Tc, n, k, a[N], pos[N];
typedef long long LL;
LL Ans, pre[N], nxt[N];

int main() {
  for (scanf("%d", &Tc); Tc--; Ans = 0) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      pre[i] = i - 1;
      nxt[i] = i + 1;
      pos[a[i]] = i;
    }
    int LIM = n - k + 1, L, R, now, step;
    for (int i = 1; i <= LIM; ++i) {
      L = R = now = pos[i];
      step = 0;
      while (step < k - 1 && pre[L]) {
        L = pre[L];
        ++step;
      }
      while (step < k - 1 && nxt[R]) {
        R = nxt[R];
        ++step;
      }
      while (L <= now) {
        if (R > n)
          break;
        Ans += (LL)i * (L - pre[L]) * (nxt[R] - R);
        L = nxt[L];
        R = nxt[R];
      }
      nxt[pre[now]] = nxt[now];
      pre[nxt[now]] = pre[now];
    }
    printf("%lld\n", Ans);
  }
  return 0;
}
