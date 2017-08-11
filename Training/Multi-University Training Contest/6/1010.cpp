#include <cstdio>
#include <cstring>

const int N = 510;
int in[N], Tc, n, k;

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d%d", &n, &k);
    // tot = 0;
    // memset(head, 0, sizeof(head));
    memset(in, 0, sizeof in);
    for (int i = 2, x; i <= n; ++i) {
      scanf("%d", &x);
      if (in[x] || in[i])
        --k;
      else {
        ++in[x];
        ++in[i];
      }
    }
    bool flag = 0;
    for (int i = 1; i <= n; ++i)
      if (!in[i])
        flag = 1;
    if (flag || k < 0)
      puts("Alice");
    else
      puts("Bob");
  }
  return 0;
}
