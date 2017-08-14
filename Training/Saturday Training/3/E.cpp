#include <bits/stdc++.h>

const int N = 1000010;
char S[N];
int Next[N], n, Tc;
bool vis[N];

int main() {
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%s", S + 1);
    n = strlen(S + 1);
    memset(Next, 0, sizeof Next);
    memset(vis, 0, sizeof vis);
    for (int i = 1, j = 0; i <= n; i++) {
      while (j && (S[j + 1] != S[i]))
        j = Next[j];
      if ((S[j + 1] == S[i]) && (i != 1))
        j++;
      Next[i] = j;
      if (j + j <= i && j + i <= n)
        vis[j] = 1;
    }
    int i;
    for (i = Next[n]; i; i = Next[i])
      if (vis[i])
        break;
    printf("%d\n", i);
  }
  return 0;
}
