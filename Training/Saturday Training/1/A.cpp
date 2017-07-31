#include<cstdio>
#include<cstring>
#include<set>
#include<map>

using namespace std;

const int N = 60010;

struct lr {
	int x[6];
} v[N];

map<int, int> A[33];
map<int, int>::iterator it;
int n, K, Tc;

int calc(int i, int s) {
	int tmp = 0;
	for(int k = 0; k < K; ++k) {
		if(s & (1 << k)) {
			tmp += v[i].x[k];
		}
		else {
			tmp -= v[i].x[k];
		}
	}
	return tmp;
}

int main() {
	while(~scanf("%d%d", &Tc, &K)) {
		int Lim = (1 << K) - 1, od;
		for(int i = Lim; i >= 0; --i) {
			A[i].clear();
		}
		for(int i = 1; i <= Tc; ++i) {
			scanf("%d", &od);
			if(od) {
				int idx;
				scanf("%d", &idx);
				for(int s = 0; s <= Lim; ++s) {
					int ret = calc(idx, s);
					A[s][ret]--;
					if(A[s][ret] == 0) {
						A[s].erase(ret);
					}
				}
				int ans = 0;
				for(int s = 0; s <= Lim; ++s) {
					ans = min(ans, (*A[s].begin()).first + (*A[s ^ Lim].begin()).first);
				}
				printf("%d\n", -ans);
			}
			else {
				for(int j = 0; j < K; ++j) {
					scanf("%d", &v[i].x[j]);
				}
				for(int s = 0; s <= Lim; ++s) {
					int ret = calc(i, s);
					A[s][ret]++;
				}
				int ans = 0;
				for(int s = 0; s <= Lim; ++s) {
					ans = min(ans, (*A[s].begin()).first + (*A[s ^ Lim].begin()).first);
					//printf("	%d %d\n", s, ans);
				}
				printf("%d\n", -ans);
			}
		}
	}
	return 0;
}
