#include <cstdio>

int main() {
  int Tc, n;
  for (scanf("%d", &Tc); Tc--;) {
    scanf("%d", &n);
    int a = 0, b = 0, x;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x);
      x & 1 ? a++ : b++;
    }
    printf("2 ");
    if (a > b)
      puts("1");
    else
      puts("0");
  }
  return 0;
}
