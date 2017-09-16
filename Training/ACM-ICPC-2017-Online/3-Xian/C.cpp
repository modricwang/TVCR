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
char s[10], n;

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 1; i <= 233; ++i) {
      printf("1");
      for (int j = 1; j < n; ++j)
        printf("0");
    }
    puts("");
  }
  return 0;
}
