#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#else
  freopen("in.txt", "r", stdin);
#endif
  long long n, m;
  while (cin >> n >> m) {
    if (n > m)
      swap(n, m);
    long long g = __gcd(n, m);
    // long long tot = n / g * m;
    long long n2 = n - 1;
    long long m2 = m - 1;
    long long g2 = __gcd(m2, n2);
    long long tot = n2 / g2 * m2 + 1;
    long long x2 = n2 / g2;
    long long y2 = m2 / g2;
    long long f1 = (x2 - 1) / 2;
    long long f2 = x2 - f1 - 1;
    long long gg1 = (y2 - 1) / 2;
    long long gg2 = y2 - gg1 - 1;
    // long long det1 = ((n ) / (g + 1)) * ((m ) / (g + 1));
    // long long det2 = ((n - 1) / (g + 1) + 1) * ((m - 1) / (g + 1) + 1);
    long long det1 = ((n - 1) / (g + 1)) * ((m - 1) / (g + 1));
    long long det2 = ((n - 2) / (g + 1)) * (((m - 2) / (g + 1)));
    // cout << tot << " " << x2 << " " << y2 << "\n";
    // cout << g2 << " " << g << " " << det1 << " " << det2 << " " << tot <<
    // "\n";
    det1 *= 2;
    det2 *= 2;
    // cout << tot - det1 - det2 << "\n";
    cout << tot - 2 * (f1 * gg1 + f2 * gg2) << "\n";
  }
}
