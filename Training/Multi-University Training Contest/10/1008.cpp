#include <cstdio>
#include <cstring>

const int N = 100005, M = N;
int n, K, fa[N];
bool vis[N];
int siz, ans;

int aa;
char ch;

int F() {
  while (ch = getchar(), ch < '0' || ch > '9')
    ;
  aa = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9')
    aa = aa * 10 + ch - '0';
  return aa;
}

namespace IO {
const int MT = 30 * 1024 * 1024;
char IO_BUF[MT];
int IO_PTR, IO_SZ;

void begin() {
  IO_PTR = 0;
  IO_SZ = fread(IO_BUF, 1, MT, stdin);
}

template <typename T> inline bool scan_d(T &t) {
  while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' &&
         (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
    IO_PTR++;
  if (IO_PTR >= IO_SZ)
    return false;
  bool sgn = false;
  if (IO_BUF[IO_PTR] == '-')
    sgn = true, IO_PTR++;
  for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9';
       IO_PTR++)
    t = t * 10 + IO_BUF[IO_PTR] - '0';
  if (sgn)
    t = -t;
  return true;
}

inline bool scan_s(char s[]) {
  while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n'))
    IO_PTR++;
  if (IO_PTR >= IO_SZ)
    return false;
  int len = 0;
  while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n')
    s[len++] = IO_BUF[IO_PTR], IO_PTR++;
  s[len] = '\0';
  return true;
}

template <typename T> void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x)
    *s1++ = '0';
  if (x < 0)
    putchar('-'), x = -x;
  while (x)
    *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s)
    putchar(*s1);
}

template <typename T> void println(T x) {
  print(x);
  putchar('\n');
}
}; // namespace IO

int main() {
  IO::begin();
  register int Tc, i;
  IO::scan_d(Tc);
  while (Tc--) {
    IO::scan_d(n);
    IO::scan_d(K);
    for (i = 2; i <= n; ++i) {
      IO::scan_d<int>(fa[i]);
    }
    memset(vis, 0, sizeof(bool) * (n + 1));
    ans = siz = 0;
    for (i = n; i; --i) {
      if (vis[i])
        ++siz;
      else
        vis[fa[i]] = 1;
    }
    if ((K >> 1) < siz) {
      ans = K >> 1;
      if (K & 1)
        ++ans;
    } else {
      ans = K - siz;
    }
    printf("%d\n", ans);
    // IO::println(ans);
  }
  return 0;
}
