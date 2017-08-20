#include <algorithm>
#include <cstdio>
#include <cstring>

using std::max;
const int MaxN = (int)1e6 + 7;
const long long mod = (long long)1e9 + 7;

int Next[MaxN];
long long Ext[MaxN];
long long tot[MaxN];
long long ans;

void pre_EKMP(char x[], int m, int next[]) {
  next[0] = m;
  int j = 0;
  while (j + 1 < m && x[j] == x[j + 1])
    j++;
  next[1] = j;
  int k = 1;
  for (int i = 2; i < m; i++) {
    int p = next[k] + k - 1;
    int L = next[i - k];
    if (i + L < p + 1)
      next[i] = L;
    else {
      j = max(0, p - i + 1);
      while (i + j < m && x[i + j] == x[j])
        j++;
      next[i] = j;
      k = i;
    }
  }
}

void EKMP(char x[], int m, char y[], int n, int next[], long long extend[]) {
  pre_EKMP(x, m, next);
  int j = 0;
  while (j < n && j < m && x[j] == y[j])
    j++;
  extend[0] = j;
  int k = 0;
  for (int i = 1; i < n; i++) {
    int p = extend[k] + k - 1;
    int L = next[i - k];
    if (i + L < p + 1)
      extend[i] = L;
    else {
      j = max(0, p - i + 1);
      while (i + j < n && j < m && y[i + j] == x[j])
        j++;
      extend[i] = j;
      k = i;
    }
  }
}

int T, len1, len2;
char ch1[MaxN], ch2[MaxN];

int main() {

  scanf("%d", &T);
  while (T--) {
    scanf("%s", ch1);
    scanf("%s", ch2);
    len1 = strlen(ch1);
    len2 = strlen(ch2);
    char t;
    for (int i = 0; i + i < len1; i++) {
      t = ch1[i];
      ch1[i] = ch1[len1 - i - 1];
      ch1[len1 - i - 1] = t;
    }
    for (int i = 0; i + i < len2; i++) {
      t = ch2[i];
      ch2[i] = ch2[len2 - i - 1];
      ch2[len2 - i - 1] = t;
    }
    pre_EKMP(ch2, len2, Next);
    EKMP(ch2, len2, ch1, len1, Next, Ext);

    // memset(tot, 0, sizeof(tot));
    ans = 0;

    /* DEBUG */
    for (int i = 0; i < len1; i++) {
      ans += (Ext[i] * (Ext[i] + 1) / 2) % mod;
      ans %= mod;
    }
    /* END */

    printf("%lld\n", ans);
  }
}
