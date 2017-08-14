#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  while (cin >> n >> k && n > 0 && k > 0) {
    if ((n - 1) % (k + 1) == 0) {
      cout << "Jiang\n";
    } else {
      cout << "Tang\n";
    }
  }
}
