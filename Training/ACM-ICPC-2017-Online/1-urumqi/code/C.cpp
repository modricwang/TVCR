#include <iostream>

using namespace std;

const int Size = 1023;

int c[Size];
int d[Size];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T;
  cin >> T;
  while (T--) {
    bool succ = true;
    int n, b;
    int tot = 0;
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
      cin >> d[i];
    }
    tot = c[1];
    for (int i = 2; i <= n; i++) {
      tot -= (d[i - 1] * b);
      if (tot < 0)
        succ = false;
      tot += c[i];
    }
    if (succ)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
