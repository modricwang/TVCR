#include <cstdio>

namespace IO {

// MT means bytes of total file size
// Too large can cause MLE
// Too small can cause read not complete
// Now its size is 30MB
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

// TODO: call IO::begin() before using
// HINT: output sometimes template
