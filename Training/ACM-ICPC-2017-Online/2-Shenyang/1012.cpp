#include <cstring>
#include <iostream>

using namespace std;

const int MaxN = (int)1e6 + 7;

int asum[MaxN * 2];
int det[MaxN * 2];

template <class T> inline bool scan_d(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF)
    return 0; // EOF
  while (c != '-' && (c < '0' || c > '9'))
    c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9')
    ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}

int n;

int getA(int l, int r) {
  if (l <= r) {
    return asum[r] - asum[l - 1];
  } else {
    return asum[n] - asum[l - 1] + asum[r];
  }
}

int Det(int i) { return det[(i - 1) % n + 1]; }

// inline void out(int x) {
//    if (x > 9) out(x / 10);
//    putchar(x % 10 + '0');
//    putchar('\n');
//}

int main() {

  while (scan_d(n)) {
    asum[0] = det[0] = 0;
    for (int i = 1; i <= n; i++) {
      scan_d(asum[i]);
      asum[i + n] = asum[i];
    }
    for (int i = 1; i <= n; i++) {
      //            int x;
      //            scan_d(x);
      //            det[i] = asum[i] - x;
      //
      scan_d(det[i]);
      det[i + n] = det[i];
    }
    //        for (int i = 1; i <= n + n; i++) {
    //            asum[i] += asum[i - 1];
    //        }
    int pos = 0;
    int nowval = 0;
    int nowscore = 0;
    int nowbegin = 0;
    int maxscore = 0;
    int maxmove = 0;
    while (pos <= n + n) {
      pos++;
      nowval += asum[pos];
      nowval -= det[pos];
      nowscore += asum[pos];
      if (nowscore > maxscore) {
        maxscore = nowscore;
        maxmove = nowbegin;
      }
      if (nowval < 0) {
        nowval = 0;
        nowbegin = pos;
        nowscore = 0;
        if (nowbegin > n)
          break;
      }
    }
    printf("%d\n", maxmove);
  }
}
