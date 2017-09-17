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

map<string, int> a;
string s1, s2;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int Tc;
  a["rat"] = 12;
  a["ox"] = 11;
  a["tiger"] = 10;
  a["rabbit"] = 9;
  a["dragon"] = 8;
  a["snake"] = 7;
  a["horse"] = 6;
  a["sheep"] = 5;
  a["monkey"] = 4;
  a["rooster"] = 3;
  a["dog"] = 2;
  a["pig"] = 1;
  cin >> Tc;
  while (Tc--) {
    cin >> s1 >> s2;
    int ans = a[s1] - a[s2];
    if (ans <= 0)
      ans += 12;
    cout << ans << '\n';
  }
  return 0;
}
