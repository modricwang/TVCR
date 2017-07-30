#include<cstdio>
#include<cstring>
#include<bitset>


const int N = 1010;
std::bitset<N> v[12], ans;
int n;
char s[5000010];

int main() {
	scanf("%d", &n);
	for(int i = 0, t, x, j; i != n; ++i) {
		scanf("%d", &x);
		for(j = 0; j != x; ++j) {
			scanf("%d", &t);
			v[t].set(i);
		}
	}
	scanf("%s", s);
	int len = strlen(s);
	--n;
	for(int i = 0; i != len; ++i) {
		ans <<= 1;
		ans[0] = 1;
		ans &= v[s[i] - '0'];
		if(ans.test(n)) {
			char tmp = s[i+1];
			s[i+1] = 0;
			puts(s + i - n);
			s[i+1] = tmp;
		}
	}
	return 0;
}
