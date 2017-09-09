#include <cstring>
#include <iostream>

using namespace std;

const int MaxSize = 55;

bool vis[MaxSize][MaxSize];
int a1[MaxSize][2];
int a2[MaxSize][2];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a1[i][0] >> a1[i][1];
    }
    for (int i = 0; i < m; i++) {
      cin >> a2[i][0] >> a2[i][1];
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a1[i][1] == a2[j][0]) {
          vis[a1[i][0]][a2[j][1]] = true;
        }
      }
    }
    for (int i = 1; i < MaxSize; i++) {
      for (int j = 1; j < MaxSize; j++) {
        if (vis[i][j]) {
          cout << i << " " << j << "\n";
        }
      }
    }
    cout << "\n";
  }
}
