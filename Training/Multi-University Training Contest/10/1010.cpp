#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

const int MaxN = 100000 + 10;
pair<int, int> lines[MaxN];

#define tail second
#define head first

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T;
  cin >> T;
  while (T--) {
    long long headcnt = 0, headsum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> lines[i].head >> lines[i].tail;
    }
    sort(lines, lines + n);
    multiset<int> ms;
    ms.clear();
    ms.insert(lines[0].tail);
    headcnt = 1;
    headsum = lines[0].head;
    multiset<int>::iterator it;
    for (int i = 1; i < n; i++) {
      // cout << lines[i].head << " " << lines[i].tail << "\n";
      it = ms.lower_bound(lines[i].head);
      if (*it != lines[i].head && it == ms.begin()) {
        headcnt++;
        headsum += lines[i].head;
        ms.insert(lines[i].tail);
        // cout << "   " << lines[i].head << "\n";
      } else {
        if (*it != lines[i].head)
          it--;
        ms.erase(it);
        ms.insert(lines[i].tail);
      }
    }
    long long sum = 0;
    for (it = ms.begin(); it != ms.end(); it++) {
      sum += (long long)(*it);
      // cout << (*it) << "\n";
    }
    sum -= headsum;
    cout << headcnt << " " << sum << "\n";
  }
}
