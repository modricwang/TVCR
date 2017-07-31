#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

typedef long long LL;
const int N = 110;
const int Mod = 1000000007;

using std::min;
using std::max;
using std::sort;
using std::vector;
int n, m, ans[N][N];
bool vis[N][N];
vector<int> A[N];

void postexe() {
	for(int i = 1; i <= m; ++i) {
		int t = 1;
		for(int j = 3; j <= n; ++j) {
			while(vis[i][t]) ++t;
			vis[i][t] = 1;
			ans[i][j] = t;
		}
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		int now = 0;
		for(int i = 1; i <= n; ++i) A[i].clear();
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= m; ++i) {
			ans[i][1] = ++now;
			vis[i][now] = 1;
			A[now].push_back(i);
			now %= n;
		}
		for(int i = 1; i <= n; ++i) {
			int t = now;
			for(unsigned j = 0; j < A[i].size(); ++j) {
				++t;
				if(t == i) {
					t %= n;
					++t;
				}
				ans[A[i][j]][2] = t;
				vis[A[i][j]][t] = 1;
				t %= n;
			}
		}
		postexe();
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) printf("%d ", ans[i][j]);
			puts("");
		}
	}
	return 0;
}
