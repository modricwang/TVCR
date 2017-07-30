#include<cstdio>
#include<cstring>

const int N = 1000010;

int n, K, f[N];
char s[N];

void getfail() {
	f[0] = 0;
	for(int i = 1, j; i < n; ++i) {
		for(j = f[i]; j && s[i] != s[j]; j = f[j]);
		f[i + 1] = s[i] == s[j] ? j + 1 : 0;
	//	printf("%d:%d ",i, f[i]);
	}
//	puts("");
}

int main() {
	scanf("%d%d%s", &n, &K, s);
	getfail();
	for(int i = 0; i < n; ++i) {
		f[i] = f[i + 1] - 1;
		int t = i - f[i], cnt = (i + 1) / t;
		if((i + 1) % t == 0) {
			cnt % K <= cnt / K ? putchar('1') : putchar('0');
		}
		else {
			cnt % K < cnt / K ? putchar('1') : putchar('0');
		}
	}
	return 0;
}
