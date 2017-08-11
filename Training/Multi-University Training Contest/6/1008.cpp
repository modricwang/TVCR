#include <bits/stdc++.h>

using namespace std;
int Tc, n, m, ans, a[5010];
char s[5010];

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &m);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    ans = 0;
    for (int st = 1; st < n; ++st) {
      int i = st, j = n, tot = 0, ret = 0;
      while (i < j) {
        a[++tot] = abs(s[i] - s[j]);
        ++i, --j;
      }
      j = 0;
      while (j < tot && ret + a[j + 1] <= m) {
        ret += a[++j];
      }
      ans = max(j, ans);
      for (int i = 1; i <= tot; ++i) {
        if (j == tot)
          break;
        ret -= a[i];
        while (j < tot && ret + a[j + 1] <= m) {
          ret += a[++j];
        }
        ans = max(j - i, ans);
      }
    }
    for (int ed = n; ed > 1; --ed) {
      int i = 1, j = ed, tot = 0, ret = 0;
      while (i < j) {
        a[++tot] = abs(s[i] - s[j]);
        ++i, --j;
      }
      j = 0;
      while (j < tot && ret + a[j + 1] <= m) {
        ret += a[++j];
      }
      ans = max(j, ans);
      for (int i = 1; i <= tot; ++i) {
        if (j == tot)
          break;
        ret -= a[i];
        while (j < tot && ret + a[j + 1] <= m) {
          ret += a[++j];
        }
        ans = max(j - i, ans);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
