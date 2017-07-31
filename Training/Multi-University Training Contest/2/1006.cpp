#include<cstdio>
#include<cstring>

const int Mod = 1000000007;
typedef long long LL;

LL ans, n, m, Tmp;

long long exgcd(long long a,long long b,long long c) {
    a%=b; c%=b;
    if(c==0) return 0;
    return (exgcd(b,a,a*b-c)*b+c)/a;
}

LL Pow(LL x, LL n) {
    if(n == 0) return 1;
    LL tmp = Pow(x, n >> 1);
    return n & 1 ? tmp * tmp % Mod * x % Mod : tmp * tmp % Mod;
}

int main() {
    int Tc;
    for(scanf("%d", &Tc); Tc--; ) {
        scanf("%lld%lld", &n, &m);
        ans = Pow(2, n) - 1;
        if(ans < 0) ans += Mod;
        ans = Pow(ans, m - 1) * 2 % Mod;
        Tmp = n & 1 ? 1: 0;
        ans = (ans + Tmp) % Mod;
        ans = ans * exgcd(3, Mod, 1) % Mod;
        printf("%lld\n", ans);
    }
    return 0;
}
