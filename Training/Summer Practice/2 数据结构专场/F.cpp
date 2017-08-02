#include<cstdio>

const int N = 200010;

struct Node {
	int ls, rs, f;
} T[N * 48];

int siz, Root[N], n, m, Ans;

int Build(int l, int r) {
	int t = ++siz, mid = l + r >> 1;
	if(l != r) {
		T[t].ls = Build(l, mid);
		T[t].rs = Build(mid + 1, r);
	} else {
		T[t].f = l;
	}
	return t;
}

int Modify(int Now, int l, int r, int x, int f) {
	int t = ++siz, mid = l + r >> 1;
	T[t] = T[Now];
	if(l == r) {
		T[t].f = f;
		return t;
	}
	if(x <= mid) {
		T[t].ls = Modify(T[Now].ls, l, mid, x, f);
	} else {
		T[t].rs = Modify(T[Now].rs, mid + 1, r, x, f);
	}
	return t;
}

int Query(int t, int l, int r, int x) {
	if(l == r) return T[t].f;
	int mid = l + r >> 1;
	return x <= mid ? Query(T[t].ls, l, mid, x) :
		Query(T[t].rs, mid + 1, r, x);
}

int get(int &Now, int u) {
	int f = Query(Now, 1, n, u);
	if(f == u) return u;
	else {
		int tNow = Now, ret = get(tNow, f);
		Now = Modify(tNow, 1, n, u, ret);//order
		return ret;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	Root[0] = Build(1, n);
	for(int i = 1, ty, x, y; i <= m; ++i) {
		scanf("%d", &ty);
		Root[i] = Root[i - 1];
		if(ty == 1) {
			scanf("%d%d", &x, &y);
			x = get(Root[i], x ^ Ans), y = get(Root[i], y ^ Ans);

			//printf("	%d %d\n", x, y);
			if(x != y) {
				Root[i] = Modify(Root[i - 1], 1, n, x, y);
			}
		} else if(ty == 2) {
			scanf("%d", &x);
			Root[i] = Root[x ^ Ans];
		} else {
			scanf("%d%d", &x, &y);
			x = get(Root[i], x ^ Ans), y = get(Root[i], y ^ Ans);
			Ans = x == y;
			printf("%d\n", Ans);
		}
		//for(int j = 1; j <= n; ++j) printf("%d ", Query(Root[i], 1, n, j));
		//puts("sad");
	}

	return 0;
}
