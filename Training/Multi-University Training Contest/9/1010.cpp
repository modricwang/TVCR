#include <cstdio>
#include <cstring>

using namespace std;

struct State {
  int s;
  int c;
  // State(int s = 0, int c = 0) : s(s), c(c) {}
};

const int N = 2500;
int times;
char str[N + 10];
int a[N + 10], b[N + 10];
int l1, l2;
State dp[N + 10][N + 10];

void input(int a[], int &la) {
  scanf("%s", str);
  int l = strlen(str);

  la = 0;
  int c = 0;
  for (int i = 0; i < l; i++) {
    if (str[i] == '.')
      c = 0;
    else if (str[i] >= 'a' && str[i] <= 'z')
      c = str[i] - 'a' + 1;
    else if (str[i] >= 'A' && str[i] <= 'Z')
      c = str[i] - 'A' + 26 + 1;

    if (str[i + 1] == '*')
      c += 100, i++;
    a[++la] = c;
  }
}

int main() {
  //#ifndef ONLINE_JUDGE
  //    freopen("input.txt", "r", stdin);
  //    freopen("output.txt", "w", stdout);
  //#endif

  scanf("%d", &times);
  for (int T = 1; T <= times; T++) {
    input(a, l1);
    input(b, l2);

    memset(dp, 0, sizeof(dp));
    dp[0][0].s = 1;
    int now = 1;
    while (now <= l2 && b[now] >= 100) {
      dp[0][now].s = 1;
      now++;
    }
    for (int i = 1; i <= l1; i++)
      for (int j = 1; j <= l2; j++) {
        if (b[j] < 100) {
          if ((a[i] == b[j] || b[j] == 0) && dp[i - 1][j - 1].s == 1)
            dp[i][j].s = 1;
        } else if (b[j] == 100) {
          if (dp[i][j - 1].s == 1) {
            dp[i][j].s = 1;
          } else if (dp[i - 1][j - 1].s == 1) {
            dp[i][j].s = 1;
            dp[i][j].c = a[i];
          } else if (dp[i - 1][j].s == 1 && dp[i - 1][j].c == a[i]) {
            dp[i][j].s = 1;
            dp[i][j].c = a[i];
          }
        } else if (b[j] > 100) {
          if (dp[i][j - 1].s == 1) {
            dp[i][j].s = 1;
          } else if (dp[i - 1][j - 1].s == 1 && a[i] == b[j] - 100) {
            dp[i][j].s = 1;
          } else if (dp[i - 1][j].s == 1 && a[i] == b[j] - 100) {
            dp[i][j].s = 1;
          }
        }
      }

    if (dp[l1][l2].s == 1)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
