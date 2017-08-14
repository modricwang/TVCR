#include <iostream>
#include <string>

using namespace std;

const int MaxN = 1e5 + 7;
int n, m, k, cnt, len, l;

int s1[MaxN], s2[MaxN];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; i++)
      cin >> s1[i];
    for (int i = 0; i < m; i++)
      cin >> s2[i];
    cnt = 0;
    for (int i = 0; i <= n - m; i++) {
      len = 0;
      l = i;
      for (int j = 0; l < m + i - 1; j++) {
        if ((s1[l] == s1[l + 1] && s2[j] == s2[j + 1]) ||
            (s1[l] > s1[l + 1] && s2[j] > s2[j + 1]) ||
            (s1[l] < s1[l + 1] && s2[j] < s2[j + 1])) {
          len++;
        } else
          break;
        l++;
      }
      if (len == m - 1) {
        cnt++;
        i += m - 1;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
