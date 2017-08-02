#include<cstdio>
#include<cstring>
#include<algorithm>

using std::swap;

const int N = 100005 * 2;

int f[N], siz[N], n, m, now[N], rpst[N];
long long sum[N];

int get(int u) {
	return u == f[u] ? u : get(f[u]);
}

void Remove(int u, int x) {
	--siz[u];
	sum[u] -= x;
	if(u != f[u]) Remove(f[u], x);
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		int u, v, t, tot = n, ty;
		for(int i = 1; i <= n + m; ++i)
			siz[sum[i] = rpst[i] = now[i] = f[i] = i] = 1;
		while(m--) {
			scanf("%d", &ty);
			if(ty == 1) {
				scanf("%d%d", &u, &v);
				u = now[u], v = now[v];
				u = get(u), v = get(v);
				if(u != v) {
					if(siz[u] > siz[v]) swap(u, v);
					sum[v] += sum[u];
					siz[f[u] = v] += siz[u];
				}
			} else if(ty == 2) {
				scanf("%d%d", &u, &v);
				v = now[v];
				v = get(v), t = get(now[u]);
				if(v != t) {
					Remove(now[u], u);

					rpst[now[u] = ++tot] = u;
					sum[now[u]] = u;

					u = now[u];

					sum[v] += rpst[u];
					siz[f[u] = v]++;
				}
			} else {
				scanf("%d", &u);
				u = get(now[u]);
				printf("%d %lld\n", siz[u], sum[u]);
			}
		}
	}
	return 0;
}
