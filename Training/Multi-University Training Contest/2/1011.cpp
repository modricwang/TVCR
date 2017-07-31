#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<bitset>

using std::min;
using std::max;
using std::sort;

const int N = 510, M = 510;
const int Mod = 1000000007;
typedef long long LL;
typedef long double LD;

bool vis[N][N];
int n, x[M], y[M], ans;

bool check(int x, int y) {
    if(x >= 0 && x < N && y >= 0 && y < N)
        return vis[x][y];
    return 0;
}

int main() {
    while(~scanf("%d", &n)) {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x + i, y + i);
            x[i] += 110;
            y[i] += 110;
            vis[x[i]][y[i]] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            for(int lx = 0; lx <= 200; ++lx)
            for(int ly = 1; ly <= 200; ++ly)
            if(lx + ly != 0) {
                int a = x[i] + lx, b = y[i] + ly;
                if(!check(a, b)) continue;
                a = x[i] + ly, b = y[i] - lx;
                if(!check(a, b)) continue;
                a = x[i] + ly + lx, b = y[i] + ly - lx;
                if(!check(a, b)) continue;
                ++ans;
            }
            //printf("    %d %d %d \n", x[i], y[i], ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
