#include <cstring>
#include <iostream>

using namespace std;

const int MaxN = 110;

int p[MaxN];
bool mark[MaxN];

int n, m, q, T, fb;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    memset(mark, 0, sizeof(mark));
    cin >> q;
    while (q--) {
      cin >> fb;
      mark[fb] = true;
    }
    int ans1, ans2, anssum = 10000;
    for (int l = 0; l < n; l++) {
      if (mark[l])
        continue;
      int cnt = 1, scnt = 1;
      int s1 = 1010, s2 = 1010;
      int p1, p2;
      int r = l + 1;
      s1 = p[l];
      p1 = l;
      //            cout << l << "\n";
      while (cnt < m && r < n) {
        if (!mark[r]) {
          if (p[r] <= s2) {
            s2 = p[r];
            p2 = r;
            scnt++;
          }
          cnt++;
          r++;
        } else {
          r++;
        }
        //                cout << cnt << "\n";
        //                cout << "\t" << s1 << " " << s2 << "\n";
        //                cout << "\t" << p1 << " " << p2 << "\n";
      }
      if (scnt >= 2 && cnt == m) {
        if (s1 + s2 < anssum) {
          anssum = s1 + s2;
          ans1 = p1;
          ans2 = p2;
        }
      }
    }
    // cout << anssum << "\n";
    cout << ans1 << " " << ans2 << "\n";
  }
}
