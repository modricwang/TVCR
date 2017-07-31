#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<bitset>

using std::min;
using std::max;
using std::sort;

const int N = 80010;
const int Mod = 1000000007;
typedef long long LL;
typedef long double LD;
char str1[N], str2[N];

int main() {
    int Tc;
    for(scanf("%d", &Tc); Tc--; ) {
        int n, x, y, same = 0, diff = 0;
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s%s", str1, str2);
        for(int i = 0; i < n; ++i) {
            same += str1[i] == str2[i];
        }
        diff = n - same;
        //printf("%d %d\n", diff, same);
        if(abs(x - y) <= diff && x + y <= same * 2 + diff) puts("Not lying");
            else puts("Lying");
    }
    return 0;
}
