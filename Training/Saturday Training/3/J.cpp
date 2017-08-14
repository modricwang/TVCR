#include <bits/stdc++.h>

using std::min;
using std::max;

const int N = 20010;

int Tc, n;
long long A[N], B[N], C[N];

bool even(long long l, long long r) {
  long long t, cl, ret = 0;
  for (int i = 1; i <= n; ++i) {
    // if(A[i] > r || B[i] < l) continue;
    if (l <= A[i]) {
      t = min(B[i], r);
      if (t < A[i])
        continue;
      ret += (t - A[i]) / C[i] + 1;
      // if((t - A[i]) % C[i] == 0) ++ret;
    } else {
      t = min(B[i], r);
      cl = (l - A[i]) / C[i] * C[i] + A[i];
      while (cl < l)
        cl += C[i];
      if (cl > t)
        continue;
      // printf("test %lld %lld \n", cl, t);
      ret += (t - cl) / C[i] + 1;
      // if((t - cl) % C[i] == 0) ++ret;
    }
    // printf("%lld\n", ret);
    ret = ret & 1;
  }
  return ret == 0;
}

int calc(unsigned x) {
  int ret = 0;
  for (int i = 1; i <= n; ++i)
    if (x >= A[i] && x <= B[i] && (x - A[i]) % C[i] == 0)
      ++ret;
  return ret;
}

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i)
      scanf("%lld%lld%lld", A + i, B + i, C + i);
    long long l = 0, r = 2147483648LL, mid;
    // printf("calc %d\n", calc(19));
    // even(7, 8);
    // for(;;);
    while (l != r) {
      mid = l + r >> 1;
      if (even(l, mid))
        l = mid + 1;
      else
        r = mid;
      // printf("	%lld %lld\n", l, r);
    }
    int ans = calc(l);
    if (ans & 1)
      printf("%lld %d\n", l, ans);
    else
      puts("DC Qiang is unhappy.");
  }
  return 0;
}
