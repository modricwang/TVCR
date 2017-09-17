#include <bits/stdc++.h>
#define INF(x) memset(x, 63, sizeof x)
#define clear(x) memset(x, 0, sizeof x)

using namespace std;
typedef long long LL;
const int N = 100010;

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
LL x, c;
int Tc;

LL cal(LL t) { return t * t + (t + 1) * (t + 1) + t * (t + 1); }

bool check(LL t) { return cal(t) >= x; }

int main() {
  scanf("%d", &Tc);
  while (Tc--) {
    scanf("%lld", &x);
    LL l = 1, r = 1000000, mid;
    while (l != r) {
      mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    if (cal(l) == x)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
