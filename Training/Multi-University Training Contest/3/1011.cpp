#include <iostream>

using namespace std;

int t, c;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  while (cin >> t) {
    int ans = 0, now;
    for (int i = 0; i < t; i++) {
      cin >> now;
      if (now <= 35)
        ans++;
    }
    cout << ans << "\n";
  }
}
