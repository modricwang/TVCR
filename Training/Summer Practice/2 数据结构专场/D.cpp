#include<cstdio>
#include<cstring>
#include<algorithm>

using std::sort;
using std::unique;
using std::lower_bound;
const int N = 100005;

int y[N], x[N], Root[N], n, Tc, sum, tsiz;

struct Node {
	int l, r, v, ls, rs;
} Tree[N * 32];

int Build(int l, int r) {
	int t = ++tsiz, mid = l + r >> 1;
	Tree[t].l = l, Tree[t].r = r;
	if(l != r) {
		Tree[t].ls = Build(l, mid);
		Tree[t].rs = Build(mid + 1, r);
	}
	return t;
}

int Modify(int Now, int x) {
	int t = ++tsiz, mid = Tree[Now].l + Tree[Now].r >> 1;
	Tree[t] = Tree[Now];
	Tree[t].v++;
	if(Tree[Now].l == Tree[Now].r) return t;
	if(x <= mid) {
		Tree[t].ls = Modify(Tree[Now].ls, x);
	} else {
		Tree[t].rs = Modify(Tree[Now].rs, x);
	}
	return t;
}

int Query(int L, int R, int K) {
	if(Tree[L].l == Tree[R].r)
		return Tree[L].l;
	int KL = Tree[Tree[R].ls].v-Tree[Tree[L].ls].v;
	return KL >= K ? Query(Tree[L].ls, Tree[R].ls, K) :
		Query(Tree[L].rs, Tree[R].rs, K - KL);
}

int rord(int x) {
	return lower_bound(y + 1, y + sum + 1, x) - y;
}

int main() {
	scanf("%d%d", &n, &Tc);
	for(int i = 1; i <= n; ++i)
		scanf("%d", x + i), y[i] = x[i];
	sort(y + 1, y + n + 1);
	sum = unique(y + 1, y + 1 + n) - y - 1;
	Root[0] = Build(1, sum);
	for(int i = 1; i <= n; ++i) {
		Root[i] = Modify(Root[i - 1], rord(x[i]));
	}
	for(int l, r, K; Tc--; ) {
		scanf("%d%d%d", &l, &r, &K);
		printf("%d\n", y[Query(Root[l - 1], Root[r], K)]);
	}
	return 0;
}
