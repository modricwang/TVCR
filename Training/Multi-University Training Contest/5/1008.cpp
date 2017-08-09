#include <cstdio>
#include <cstring>

const int N = 52, M = 10010;
int ans[N], cnt[M], n, m, f[M], Tc;

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; ++i)
      scanf("%d", cnt + i);
    int tot = 0;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i <= m; ++i) {
      if (cnt[i] != 0) {
        while (cnt[i] > 0) {
          ans[++tot] = i;
          for (int j = m; j >= i; --j) {
            f[j] += f[j - i];
            cnt[j] -= f[j - i];
          }
        }
      }
    }
    printf("%d", ans[1]);
    for (int i = 2; i <= tot; ++i)
      printf(" %d", ans[i]);
    puts("");
  }
  return 0;
}
