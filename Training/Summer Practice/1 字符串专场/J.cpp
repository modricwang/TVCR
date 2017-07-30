#include<cstdio>
#include<cstring>
#include<map>
#include<vector>

using std::vector;
using std::map;
using std::pair;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VCI;
const LL Base = 13131LL;
const int Mod = 1000000007;
const int N = 200010;

int n, Ans, hs[N], bs[N];
char s[N];

int hash(int l, int r) {
	if(l > r) return 0;
	return (hs[r] - hs[l - 1] * (LL)bs[r - l + 1] % Mod + Mod) % Mod;
}

map<PII, VCI> dp[N];
map<PII, VCI>::iterator it;

int main() {
	bs[0] = 1;
	for(int i = 1; i < N; ++i)
		bs[i] = bs[i - 1] * Base % Mod;
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i)
		hs[i] = (hs[i - 1] * Base + s[i]) % Mod;
	for(int i = 1; i <= n; ++i)
		dp[1][PII(hash(i, i), 1)].push_back(i);
	for(int i = 1; i <= n; ++i)
	if(dp[i].size()) {
		Ans = i;
		for(it = dp[i].begin(); it != dp[i].end(); ++it) {
			int len = it->first.second;
			VCI idx = it->second, mid;
			for(size_t j = 0; j + 1 < idx.size(); ++j) {
				mid.push_back(hash(idx[j] + len, idx[j + 1] - 1));
				//printf("	%d %d %d mid", hash(idx[j] + len, idx[j + 1] - 1), idx[j] + len, idx[j + 1] - 1);
			}
			//puts("");
			for(size_t l = 0, r = 0; l + 1 < idx.size(); l = r) {
				while(r + 1 < idx.size() && mid[l] == mid[r]) ++r;
				int nxt = i + r - l, nlen = idx[r] - idx[l] + len;
				dp[nxt][PII(hash(idx[l], idx[r] + len - 1), nlen)].push_back(idx[l]);
			}
		}
	}
	printf("%d\n", Ans);
	return 0;
}
