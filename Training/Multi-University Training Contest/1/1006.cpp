#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll N = 100000;
const ll Mod = 1e9 + 7;
ll times;
ll n, m;
ll a[N+10], b[N+10];
ll c[N+10], d[N+10];
bool vis[N+10];

void process(ll a[], ll n, ll s[])
{
    memset(s, 0, sizeof(ll) * (N+1));
    memset(vis, 0, sizeof(bool) * (N+1));

    for (ll i = 0; i < n; i++)
    if  (!vis[i])
    {
        ll js = 0;
        for (ll j = i; !vis[j]; j = a[j])
        {   ++js;
            vis[j] = true;
        }
        s[js]++;
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    while (scanf("%lld%lld", &n, &m) != EOF)
    {
        for (ll i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for (ll i = 0; i < m; i++)
            scanf("%lld", &b[i]);

        process(a, n, c);
        process(b, m, d);

        ll sol = 1;
        for (ll i = 1; i <= n; i++)
        if  (c[i] > 0)
        {
            ll tmp = 0;
            for (ll j = 1; j * j <= i; j++)
            if  (i % j == 0)
            {   tmp +=  j * d[j];
                if  (i/j != j)  tmp += (i/j) * d[i/j];
            }

            for (ll j = 1; j <= c[i]; j++)
                (sol *= tmp)%= Mod;
            if  (sol == 0)  break;
        }

        printf("Case #%lld: %lld\n", ++times, sol);
    }
    return 0;
}
