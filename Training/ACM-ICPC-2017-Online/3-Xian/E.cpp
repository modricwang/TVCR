#include <iostream>

using namespace std;
const int Mod = 1000000007;
long long p[64];
long long xe[64];
long long xem[64];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  // a(n)=6*a(n-1)-8*a(n-2)
  p[0] = 2;
  p[1] = 7;
  p[2] = 26;
  xe[0] = 1;
  xe[1] = 2;
  xe[2] = 4;
  xem[0] = 1;
  xem[1] = 2;
  xem[2] = 4;
  int i = 2;
  while (xe[i] < 1e18) {
    i++;
    xe[i] = xe[i - 1] * 2;
    xem[i] = xe[i] % Mod;
    p[i] = (xem[i - 1] * (3 * xem[i] + 1) % Mod) % Mod;
    // cout << i << " " << xe[i] << " " << p[i] << "\n";
  }
  int endpos = i;
  long long n;
  long long ans;
  while (cin >> n) {
    long long raw = n;
    ans = 0;
    //        n -= 2;
    //        for (int i = 1; i <= endpos; i++) {
    //            if (n & (xe[i]) && !(n&xe[i+1])) ans = (ans + p[i]) % Mod;
    //        }
    long long m = n / 2;
    int pos = endpos;
    while (xe[pos] > m)
      pos--;
    while (n > 2 && pos >= 0) {
      if (n > 2 * xe[pos]) {
        long long r = (n - 1) / xe[pos];
        ans += (r - 1) * p[pos];
        ans %= Mod;
        n -= (r - 1) * xe[pos];
      } else {
        pos--;
      }
      // cout << n << " " << ans << " " << pos << " " << xe[pos] << " " <<
      // p[pos] << "\n";
    }
    // if (raw & 1) ans++;

    if (n == 2)
      ans += 1;
    //        if (raw == 2) ans = 1 ;
    //        if (raw == 3) ans = 3 ;
    //        if (raw == 4) ans = 5 ;
    //        if (raw == 5) ans = 10;
    ans %= Mod;
    cout << ans << "\n";
  }
}
