#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
// using namespace std;

const int N = 100000;
const int S = N * 2;
int times;
int n, m;
char str[N + 10];

int son[S + 10][27], par[S + 10], len[S + 10];
int size = 1, root = 1, last = 1;
int num[S + 10];

void Extend(int c) {
  int np = ++size, p = last;
  len[np] = len[p] + 1;

  while (p && !son[p][c])
    son[p][c] = np, p = par[p];
  if (!p)
    par[np] = root;
  else {
    int q = son[p][c];
    if (len[q] == len[p] + 1)
      par[np] = q;
    else {
      int nq = ++size;
      memcpy(son[nq], son[q], sizeof(son[nq]));
      len[nq] = len[p] + 1;
      par[nq] = par[q];
      while (p && son[p][c] == q)
        son[p][c] = nq, p = par[p];
      par[q] = par[np] = nq;
    }
  }
  last = np;
}

int st[S + 10], id[S + 10];

void TopoSort() {
  for (int i = 0; i <= size; i++)
    st[i] = 0;
  for (int i = 1; i <= size; i++)
    st[len[i]]++;
  for (int i = 0; i <= size; i++)
    st[i] += st[i - 1];
  for (int i = 1; i <= size; i++)
    id[st[len[i]]--] = i;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  scanf("%d", &times);
  for (int T = 1; T <= times; T++) {
    scanf("%d", &m);
    scanf("%s", str);
    n = strlen(str);

    size = 1;
    root = 1;
    last = 1;
    memset(son, 0, sizeof(son));
    memset(par, 0, sizeof(par));
    memset(len, 0, sizeof(len));
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; i++)
      Extend(str[i] - 'a'), num[last]++;

    TopoSort();

    for (int i = size; i >= 1; i--) {
      int x = id[i];
      if (par[x])
        num[par[x]] += num[x];
    }

    int ans = 0;
    for (int i = 1; i <= size; i++)
      if (num[i] == m)
        ans += len[i] - len[par[i]];

    printf("%d\n", ans);
  }
  return 0;
}
