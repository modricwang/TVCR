#include<cstdio>
#include<cstring>

typedef long long LL;
const int N = 300010;
const LL Mod = 1000000007;
int n, m, K, a[N];
LL ans[N], c[N], cnt[N];

LL exgcd(LL a, LL b, LL c) {
	a %= b, c %= b;
	if(!c) return 0;
	return (exgcd(b, a, a * b - c) * b + c) / a;
}
inline void Add(int &a, LL b) {
	a += b;
	if(a >= Mod) a -= Mod;
}

LL Pow(LL x, LL n) {
	if(n == 0) return 1;
	LL tmp = Pow(x, n >> 1);
	return n & 1 ? tmp * tmp % Mod * x % Mod : tmp * tmp % Mod;
}

int main() {
	while(~scanf("%d%d%d", &n, &m, &K)) {
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		c[n - K] = 1;
		for(int i = n - K + 1; i <= n; ++i) {
			c[i] = (c[i - 1] * i) % Mod * exgcd(i - n + K, Mod, 1) % Mod;
		}
		//exgcd(i - n + K, Mod, 1)
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			++cnt[a[i]];
		}
		for(int d = m; d; --d) {
			int sum = cnt[d];
			LL tmp = 0;
			for(int j = d + d; j <= m; j += d) {
				sum += cnt[j];
				tmp = (tmp + ans[j]) % Mod;
			}
			if(sum < n - K) {
				ans[d] = 0;
				continue;
			}
			int t = m / d;
			ans[d] = c[sum] * Pow(t - 1, sum - n + K) % Mod *
				Pow(t, n - sum) % Mod;
			ans[d] = (ans[d] - tmp + Mod) % Mod;
		}
		printf("%lld", ans[1]);
		for(int i = 2; i <= m; ++i) printf(" %lld", ans[i]);
		puts("");
	}
	return 0;
}
