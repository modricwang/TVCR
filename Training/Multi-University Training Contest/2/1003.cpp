#include<cstdio>
#include<cstring>
#include<algorithm>

using std::max;
typedef long long LL;
const int N = 250010;
const LL Mod = 1000000007LL;

LL a[N], b[N], Max[N];
int n;

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
            a[i] -= i;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", b + i);
        }
        std::sort(b + 1, b + 1 + n);
        Max[n] = a[n];
        for(int i = n - 1; i; --i) {
            Max[i] = max(a[i], Max[i + 1]);
        }
        LL ans = 0, ret = 0, tmp = 0;
        for(int i = 1; i <= n; ++i) {
            tmp = max(ret, Max[b[i]]);
            ans += tmp;
            if(ans >= Mod) ans -= Mod;
            ret = max(ret, tmp - i - n);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
