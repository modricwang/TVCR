#include<cstdio>
#include<cstring>

const int Mod = 1000000007;
const int N = 400010, MaxT = 1 << 20;
typedef long long LL;

struct Node {
	int k, v, lazy;
	Node() {
		k = lazy = 1;
	}
} T[MaxT];
int v[N], deg[N];
struct Graph {
	int head[N], next[N], to[N], tot;
	void add(int x, int y) {
		to[++tot] = y;
		next[tot] = head[x];
		head[x] = tot;
	}
} G;
int in[N], out[N];

int n, Tc, dfn;

int Inv(int x) {
	return x == 1 ? 1 : (Mod - (LL)Mod / x * Inv(Mod % x) % Mod);
}


void dfs(int t) {
	//c(t);
	in[t] = ++dfn;
	for(int i = G.head[t]; i; i = G.next[i])
		dfs(G.to[i]);
	out[t] = dfn;
}

inline int mul(int &x, int v) {
	return (x = (LL)x * v % Mod);
}

inline int inc(int x, int v) {
	x += v;
	return x >= Mod ? x - Mod : x;
}

void Lazy(int t, int lazy) {
	//c(t);
	mul(T[t].lazy, lazy);
	mul(T[t].k, lazy);
	mul(T[t].v, lazy);
}
void push(int t) {
	//c(t);
	if(T[t].lazy == 1) return;
	Lazy(t << 1, T[t].lazy);
	Lazy(t << 1 | 1, T[t].lazy);
	T[t].lazy = 1;
}

void update(int t) {
	//c(t);
	T[t].v = inc(T[t << 1].v, T[t << 1 | 1].v);
}

void Modify_v(int l, int r, int x, int v, int t) {
	//c(t);
	if(l == r) {
		T[t].v = (LL)T[t].k * v % Mod;
		return;
	}
	int mid = l + r >> 1;
	push(t);
	if(x <= mid) Modify_v(l, mid, x, v, t << 1);
		else Modify_v(mid + 1, r, x, v, t << 1 | 1);
	update(t);
}

void Modify_K(int l, int r, int x, int y, int K, int t) {
	//c(t);
	if(r < x || y < l) return;
	if(x <= l && r <= y) return Lazy(t, K);
	int mid = l + r >> 1;
	push(t);
	Modify_K(l, mid, x, y, K, t << 1);
	Modify_K(mid + 1, r, x, y, K, t << 1 | 1);
	update(t);
}

int Query_v(int l, int r, int x, int y, int t) {
	//c(t);
	if(r < x || y < l) return 0;
	if(x <= l && r <= y) return T[t].v;
	int mid = l + r >> 1;
	push(t);
	return inc(Query_v(l, mid, x, y, t << 1), Query_v(mid + 1, r, x, y, t << 1 | 1));
}

int Query_K(int l, int r, int x, int t) {
	//c(t);
	if(l == r) return T[t].k;
	int mid = l + r >> 1;
	push(t);
	return x <= mid ? Query_K(l, mid, x, t << 1) : Query_K(mid + 1, r, x, t << 1 | 1);
}

int main() {
	static int u[N], f[N], ty[N];
	n = 1;
	scanf("%d%d", v + 1, &Tc);
	v[1] %= Mod;
	for(int i = 1; i <= Tc; ++i) {
		scanf("%d", ty + i);
		if(ty[i] == 1) {
			u[i] = ++n;
			scanf("%d%d", f + n, v + n);
			v[i] %= Mod;
			G.add(f[n], n);
		} else scanf("%d", u + i);
	}
	dfs(1);
	Modify_v(1, n, in[1], v[1], 1);
	deg[1] = 1;
	for(int i = 1; i <= Tc; ++i) {
		if(ty[i] == 2) {
			int Ans = Query_v(1, n, in[u[i]], out[u[i]], 1), K = 1;
			if(u[i] != 1) K = Query_K(1, n, in[f[u[i]]], 1);
			printf("%I64d\n", (LL)Ans * Inv(K) % Mod);
		} else {
			int t = f[u[i]], K = (LL)(deg[t] + 1) * Inv(deg[t]) % Mod;
			++deg[t];
			Modify_K(1, n, in[t], out[t], K, 1);
			deg[t = u[i]] = 1;
			Modify_v(1, n, in[t], v[t], 1);
		}
	}
	return 0;
}
