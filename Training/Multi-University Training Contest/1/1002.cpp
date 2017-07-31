#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
const int N = 100000 + 5;
const long long Mod = 1000000007;
int n, len, ans[26], Max;
int ord[27];
int cnt[27][N];
bool flag[27];
char s[N];

typedef long long LL;
LL ret;

int cmp(int x,int y) {
    for (int i=Max; i>=0; i--) {
        if (cnt[x][i]>cnt[y][i]) return 1;
        else if (cnt[x][i]<cnt[y][i]) return 0;
    }
    return 0;
}

int main() {
    int Tc = 0;
    while(~scanf("%d", &n)) {
        ++Tc;
        memset(cnt, 0, sizeof(cnt));
        memset(flag, 0, sizeof(flag));
        Max = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            flag[s[0] - 'a'] = 1;
            len = strlen(s);
            if(Max < len) Max = len;
            for(int j = 0; j < len; ++j) {
                cnt[s[j] - 'a'][len - 1 - j]++;
            }
        }
        for(int c = 0; c < 26; ++c)
        for(int i = 0; i < Max; ++i) {
            if(cnt[c][i] >= 26) {
                cnt[c][i+1] += cnt[c][i] / 26;
                cnt[c][i] %= 26;
            }
        }
        for (int i=0; i<26; i++) {
            ord[i]=i;
        }
        sort(ord,ord+26,cmp);
        //for(int i = 0; i < 26; ++i) printf("%c ", ord[i] + 'a');
        //for(int i = Max; i >= 0; --i) {
        //    if(cnt[][]
        //}
        int now = 1;
        memset(ans, -1, sizeof(ans));
        for(int i = 25; i >= 0; --i)
            if(!flag[ord[i]]) {
                ans[ord[i]] = 0;
                break;
            }
        for(int i = 25; i >= 0; --i)
        if(ans[ord[i]] < 0) {
            ans[ord[i]] = now++;
        }

//        for(int i = 0; i <

        ret = 0;
        LL mul = 1;
        for(int i = 0; i <= Max; ++i) {
            for(int c = 0; c < 26; ++c) {
                ret = (ret + ans[c] * cnt[c][i] % Mod * mul % Mod) % Mod;
                //printf("%d ", cnt[c][i]);
            }
//            puts("");
            mul = mul * 26 % Mod;
        }
        printf("Case #%d: %lld\n", Tc, ret);
    }
    return 0;
}
