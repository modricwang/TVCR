#include <cmath>
#include <iostream>

using namespace std;

const int MaxN = (int)2e5 + 7;

int n, m;
int arr[MaxN];

int doit(int times) {
  if (times > 20)
    return 0;
  int delta = 1 << times;
  for (int i = delta + 1; i <= n; i++) {
    arr[i] ^= arr[i - delta];
  }
}

int main() {
#ifndef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }

    for (int t = 1; m > 0; m /= 2, t++) {
      if (m & 1) {
        doit(t - 1);

        // cout << t << "\n";
        //                for (int i = 1; i < n; i++) {
        //                    cout << arr[i] << " ";
        //                }
        //                cout << arr[n] << "\n";
      }
    }

    for (int i = 1; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << arr[n] << "\n";
  }
}
