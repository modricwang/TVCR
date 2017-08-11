#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int MaxN = 100000 + 7;

int B[MaxN];
vector<pair<int, int>> p;

int main() {
#ifndef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T, n, now;
  cin >> T;
  while (T--) {
    p.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> now;
      p.emplace_back(now, i);
    }
    sort(p.begin(), p.end());
    memset(B, 0, sizeof B);
    for (int i = 2; i <= n; i++) {
      if (p[n - 1].second % i != 0) {
        B[i] = p[n - 1].first;
      } else {
        int j;
        for (j = n - 2; j >= 0 && p[j].second % i == 0; j--) {
        }
        B[i] = p[j].first;
      }
    }
    for (int i = 2; i < n; i++) {
      cout << B[i] << " ";
    }
    cout << B[n] << "\n";
  }
}
