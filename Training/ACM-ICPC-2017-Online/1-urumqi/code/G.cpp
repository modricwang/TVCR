#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int N = 100010;

int n, f[N], S, T, g[N], c[N];
char str[N], s[100], ex[10];

void getfail() {
  f[0] = f[1] = 0;
  for (int i = 1; i < T; ++i) {
    int j = f[i];
    while (j && s[j] != s[i])
      j = f[j];
    f[i + 1] = s[j] == s[i] ? j + 1 : 0;
  }
}

void Add(int x) { // para +1
  x++;
  for (; x <= S; x += x & -x)
    c[x]++;
}
void Del(int x) {
  ++x;
  for (; x <= S; x += x & -x)
    c[x]--;
}
int Get(int x, int ret = 0) { // +1
  ++x;
  for (; x; x -= x & -x)
    ret += c[x];
  return ret;
}

void find() {
  getfail();
  int j = 0;
  for (int i = 0; i < S; ++i) {
    while (j && (j >= T || s[j] != str[i]))
      j = f[j];
    if (s[j] == str[i])
      ++j;
    g[i] = j;
    if (j == T)
      Add(i);
  }
}

void init() {
  clear(f);
  clear(g);
  clear(c);
}

void def() {
  for (int i = 0; i < S; ++i)
    printf("%d\n", g[i]);
}

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    init();
    scanf("%d", &n);
    scanf("%s%s", str, s);
    S = strlen(str);
    T = strlen(s);
    find();
    for (int i = 1; i <= n; ++i) {
      scanf("%s", ex);
      if (ex[0] == 'Q') {
        int l, r;
        scanf("%d%d", &l, &r);
        --l, --r;
        l += T - 1;
        if (l > r) {
          puts("0");
        } else {
          printf("%d\n", Get(r) - Get(l - 1));
        }
      } else {
        int x, r;
        scanf("%d%s", &x, ex);
        --x;
        r = min(S - 1, x + T);
        str[x] = ex[0];
        for (int i = x; i <= r; ++i) {
          int j = i ? g[i - 1] : 0;
          // delete
          if (g[i] == T)
            Del(i);
          // Add
          while (j && (j >= T || s[j] != str[i]))
            j = f[j];
          if (s[j] == str[i])
            ++j;
          g[i] = j;
          if (j == T)
            Add(i);
        }
      }
    }
    puts("");
  }
  return 0;
}
