#include<cstdio>
#include<cstring>
#include<algorithm>

const int N = 420000;
typedef long long LL;
char s[N];
LL Ans;
int n, m, tc, len[N], tot, Next[N][30], fail[N], Last, cnt[N][2];

inline int getfail(const int &i, int x) {
	while(s[i - len[x] - 1] != s[i])
		x = fail[x];
	return x;
}

inline void Add(const int &i, const int &x, const bool &flag) {
	Last = getfail(i, Last);
	if(!Next[Last][x]) {
		len[++tot] = len[Last] + 2;
		fail[tot] = Next[getfail(i, fail[Last])][x];
		Next[Last][x] = tot;
	}
	Last = Next[Last][x];
	cnt[Last][flag]++;
}
//start from 1
inline void Input() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	s[n + 1] = 'z' + 1;
	s[n + 2] = 'z' + 2;
	n += 2;
	scanf("%s", s + 1 + n);
	m = strlen(s + 1);
	//puts(s + 1);
}

inline void Init() {
	//memset(cnt, 0, sizeof cnt);
	//memset(fail, 0, sizeof fail);
	//memset(len, 0, sizeof len);
	//memset(Next, 0, sizeof Next);
	len[1] = -1;
	Last = Ans = 0;
	fail[0] = tot = 1;
}

inline void clear() {
	for(register int i = 0, j; i <= tot; ++i) {
		cnt[i][0] = cnt[i][1] = 0;
		for(j = 0; j < 30; ++j) Next[i][j] = 0;
	}
}

int main() {
	scanf("%d", &tc);
	for(register int Tc = 1; Tc <= tc; ++Tc) {
		Input();
		Init();
		register int i;
		for(i = 1; i <= n; ++i)
			Add(i, s[i] - 'a', 0);
		for(i = n + 1; i <= m; ++i)
			Add(i, s[i] - 'a', 1);
		for(i = tot; i > 1; --i) {
			cnt[fail[i]][0] += cnt[i][0];
			cnt[fail[i]][1] += cnt[i][1];
			Ans += (LL)cnt[i][0] * cnt[i][1];
		}
		printf("Case #%d: %lld\n", Tc, Ans);
		clear();
	}
	return  0;
}

/*

6
abacab
abccab
faultydogeuniversity
hasnopalindromeatall
abbacabbaccab
youmayexpectedstrongsamplesbutnow
abacab
abccab
faultydogeuniversity
hasnopalindromeatall
abbacabbaccab
youmayexpectedstrongsamplesbutnow

*/
