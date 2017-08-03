#include <cstdio>
#include <cstring>

char s[10][30];
bool a[10];

bool v(int x, int y) { return s[x][y] == 'X'; }

int exc(int x, int y) {
  a[1] = v(1, y + 1);
  a[2] = v(2, y);
  a[3] = v(2, y + 3);
  a[4] = v(4, y + 1);
  a[5] = v(5, y);
  a[6] = v(5, y + 3);
  a[7] = v(7, y + 1);
  // for(int i = 1; i <= 7; ++i) printf("%d", a[i]);
  // puts("");
  if (a[1] && a[2] && a[3] && a[4] && a[5] && a[6] && a[7])
    return 8;
  if (a[1] && a[2] && a[3] && a[4] && !a[5] && a[6] && a[7])
    return 9;
  if (a[1] && !a[2] && a[3] && !a[4] && !a[5] && a[6] && !a[7])
    return 7;
  if (a[1] && a[2] && !a[3] && a[4] && a[5] && a[6] && a[7])
    return 6;
  if (a[1] && a[2] && !a[3] && a[4] && !a[5] && a[6] && a[7])
    return 5;
  if (!a[1] && a[2] && a[3] && a[4] && !a[5] && a[6] && !a[7])
    return 4;
  if (a[1] && !a[2] && a[3] && a[4] && !a[5] && a[6] && a[7])
    return 3;
  if (a[1] && !a[2] && a[3] && a[4] && a[5] && !a[6] && a[7])
    return 2;
  if (!a[1] && !a[2] && a[3] && !a[4] && !a[5] && a[6] && !a[7])
    return 1;
  if (a[1] && a[2] && a[3] && !a[4] && a[5] && a[6] && a[7])
    return 0;
  return 0;
}

int main() {
  int Tc;
  for (scanf("%d", &Tc); Tc--;) {
    for (int i = 1; i <= 7; ++i)
      scanf("%s", s[i] + 1);
    printf("%d", exc(1, 1));
    printf("%d:", exc(1, 6));
    printf("%d%d\n", exc(1, 13), exc(1, 18));
  }
  return 0;
}
