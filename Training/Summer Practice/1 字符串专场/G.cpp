#include<cstdio>
#include<cstring>
#include<algorithm>

const int N = 100005, Mod = 1000000007;

typedef long long LL;

char s[N];
int n, m, Last, e[N][8], f[N], len[N], tot;
LL ans, cnt[N], Inverse_element;

int getfail(int i, int x) {
	while(s[i - len[x] - 1] != s[i]) x = f[x];
	return x;
}

LL exgcd(LL a, LL b, LL c) {
	a %= b, c %= b;
	if(!c) return 0;
	return (exgcd(b, a, a * b - c) * b + c) / a;
}

void Add(int i, int x) {
	Last = getfail(i, Last);
	if(!e[Last][x]) {
		len[++tot] = len[Last] + 2;
		f[tot] = e[getfail(i, f[Last])][x];
		e[Last][x] = tot;
	}
	Last = e[Last][x];
	cnt[Last]++;
}

int main() {
	Inverse_element = exgcd(2, Mod, 1);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	len[1] = -1, f[0] = tot = 1, Last = ans = 0;
	for(int i = 1; i <= n; ++i)
		Add(i, s[i] - 'a');
	for(int i = tot; i > 1; --i) {
		cnt[f[i]] += cnt[i];
		ans = (ans + cnt[i] * (cnt[i] - 1) % Mod * Inverse_element % Mod) % Mod;
	}
	printf("%lld\n", ans);
	return 0;
}
