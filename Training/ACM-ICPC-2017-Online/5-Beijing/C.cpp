#include <bits/stdc++.h>

#define INF(x) memset(x, 63, sizeof x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int inf = 2100000000;
const int N = 303;

int Tc, n, m, p;
int sum[N][N], f[N][N][N], a[N][N], dp[N];

inline void Max(int &a, int b) {
  if (b > a)
    a = b;
}

inline void Min(int &a, int b) {
  if (b < a)
    a = b;
}

#include <cstdio>

namespace fastIO {
#define BUF_SIZE 100000
#define OUT_SIZE 1000000
bool IOerror = 0;

inline char nc() {
  static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, BUF_SIZE, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}

inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

inline int read(char *s) {
  char ch = nc();
  for (; blank(ch); ch = nc())
    ;
  if (IOerror)
    return 0;
  for (; !blank(ch) && !IOerror; ch = nc())
    *s++ = ch;
  *s = 0;
  return 1;
}

inline int RI(int &a) {
  char ch = nc();

  a = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror)
    return 0;
  int flag;
  if (ch == '-') {
    flag = -1;
    ch = nc();
  } else {
    flag = 1;
  }
  for (; !blank(ch) && !IOerror; ch = nc())
    a = a * 10 + ch - '0';
  a = a * flag;
  return 1;
}

struct Ostream_fwrite {
  char *buf, *p1, *pend;

  Ostream_fwrite() {
    buf = new char[BUF_SIZE];
    p1 = buf;
    pend = buf + BUF_SIZE;
  }

  void out(char ch) {
    if (p1 == pend) {
      fwrite(buf, 1, BUF_SIZE, stdout);
      p1 = buf;
    }
    *p1++ = ch;
  }

  void flush() {
    if (p1 != buf) {
      fwrite(buf, 1, p1 - buf, stdout);
      p1 = buf;
    }
  }

  ~Ostream_fwrite() { flush(); }
} Ostream;

inline void print(char x) { Ostream.out(x); }

inline void println() { Ostream.out('\n'); }

inline void flush() { Ostream.flush(); }

char Out[OUT_SIZE], *o = Out;

inline void print1(char c) { *o++ = c; }

inline void println1() { *o++ = '\n'; }

inline void flush1() {
  if (o != Out) {
    if (*(o - 1) == '\n')
      *--o = 0;
    puts(Out);
  }
}

struct puts_write {
  ~puts_write() { flush1(); }
} _puts;
};

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

int main() {
  while (fastIO::RI(n)) {
    fastIO::RI(m);
    fastIO::RI(p);
    register int ans = 0, Mn = inf, i, j, l, r, len;
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= m; ++j) {
        //                scanf("%d", a[i] + j);
        fastIO::RI(a[i][j]);
        ans += a[i][j];
        Min(Mn, a[i][j]);
      }
    ans += p - Mn;
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) {
        sum[i][j] = sum[i][j - 1] + a[i][j];
      }
      for (len = 1; len <= m; ++len)
        for (l = 1; l <= m; ++l) {
          r = l + len - 1;
          if (r > m)
            break;
          if (l == r)
            f[i][l][r] = a[i][r];
          else
            f[i][l][r] = min(f[i][l][r - 1], a[i][r]);
        }
    }
    for (l = 1; l <= m; ++l)
      for (r = l; r <= m; ++r) {
        if (l == 1 && r == m) {
          int ret = 0, mn = inf;
          for (i = 1; i < n; ++i) {
            if (ret < 0) {
              ret = 0;
              mn = inf;
            }
            ret += sum[i][r] - sum[i][l - 1];
            Min(mn, f[i][l][r]);
            Max(ans, ret);

            dp[i] = max(ret + p - mn, dp[i - 1] + sum[i][r] - sum[i][l - 1]);
            Max(ans, dp[i]);
          }
          ret = 0, mn = inf;
          dp[1] = 0;
          for (i = 2; i <= n; ++i) {
            if (ret < 0) {
              ret = 0;
              mn = inf;
            }
            ret += sum[i][r] - sum[i][l - 1];
            Min(mn, f[i][l][r]);
            Max(ans, ret);

            dp[i] = max(ret + p - mn, dp[i - 1] + sum[i][r] - sum[i][l - 1]);
            Max(ans, dp[i]);
          }
          continue;
        }
        int ret = 0, mn = inf;
        for (i = 1; i <= n; ++i) {
          if (ret < 0) {
            ret = 0;
            mn = inf;
          }
          ret += sum[i][r] - sum[i][l - 1];
          Min(mn, f[i][l][r]);
          Max(ans, ret);

          dp[i] = max(ret + p - mn, dp[i - 1] + sum[i][r] - sum[i][l - 1]);
          Max(ans, dp[i]);
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
