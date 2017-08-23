#include <bits/stdc++.h>

typedef long long LL;
const int N = 125250;

int n, m, ans[N], a[N];

std::multiset<int> info;
std::multiset<int>::iterator it;
int main() {
  while (~scanf("%d", &m)) {
    for (int i = 1; i <= m; ++i)
      scanf("%d", a + i);
    std::sort(a + 1, a + 1 + m);
    n = 0;
    info.clear();
    for (int i = 1; i <= m; ++i) {
      it = info.find(a[i]);
      if (it != info.end()) {
        info.erase(it);
        continue;
      }
      ans[++n] = a[i];
      for (int j = 1; j < n; ++j) {
        info.insert(ans[j] + a[i]);
      }
    }
    printf("%d\n", n);
    for (int i = 1; i < n; ++i)
      printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
  }
  return 0;
}
