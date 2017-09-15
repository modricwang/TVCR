#include <iostream>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  long long m, k, ans;
  while (cin >> m >> k) {
    ans = k + (m - k) * k;
    cout << ans << "\n";
  }
}
