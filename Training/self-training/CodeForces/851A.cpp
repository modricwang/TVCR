#include <iostream>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  long long n, k, t;
  cin >> n >> k >> t;
  long long ans;
  if (t <= k) {
    ans = t;
  } else if (t >= n) {
    ans = n + k - t;
  } else {
    ans = k;
  }
  if (ans < 0) {
    ans = 0;
  }
  cout << ans << "\n";
}
