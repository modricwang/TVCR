#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using std::max;
typedef long long LL;
const LL Mod = 1000000007;
const int N = 100010;
LL ans;
int n, a[N], mu[N], prime[N], tot, num[N], mul[N];
int cnt[N];
bool check[N];

void Moblus() {
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i <= 100000; ++i) {
        if(!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > 100000) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }
            else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

LL Pow(LL x, LL n) {
    if(n == 0) return 1;
    LL tmp = Pow(x, n >> 1);
    return n & 1 ? tmp * tmp % Mod * x % Mod : tmp * tmp % Mod;
}

int main() {
    int Tc;
    scanf("%d", &Tc);
    Moblus();
    for(int i = 2; i <= 100000; ++i) {
        if(mu[i]) {
            num[tot] = i;
            mul[tot++] = -mu[i];
        }
    }
    num[tot] = N;
    for(Tc = 1; scanf("%d", &n) == 1; ++Tc) {
        memset(cnt, 0, sizeof(cnt));
        ans=0;
        int maxx = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            cnt[a[i]]++;
            if(a[i] > maxx) maxx = a[i];
        }
        for(int i = 1; i <= maxx; ++i) cnt[i] += cnt[i-1];
        std::sort(a + 1, a + 1 + n);
        int Lim = a[1];
        for(int i = 0; num[i] <= Lim; ++i) {
            LL ret = 1;
            int k;
            for(k = num[i] - 1; k <= maxx; k += num[i]) {
                LL CNT = cnt[k] - cnt[max(k - num[i], 0)];
                ret = ret * Pow(k / num[i], CNT) % Mod;
            //    printf("    %d %lld\n", k, ret);
            }
            k -= num[i];
            LL CNT = cnt[maxx] - cnt[max(k, 0)];
            ret = ret * Pow(maxx / num[i], CNT) % Mod;
            ret *= mul[i];
            ans = (ans + ret) % Mod;
            //printf("%d %lld\n", num[i], ans);
        }
        printf("Case #%d: %lld\n", Tc, (ans + Mod) % Mod);
    }
    return 0;
}
