#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;

const int MaxN = 105;
const int MaxS = (1 << 10) + 5;
const int CharCnt = 26;
ll dp[31][MaxN][MaxS];
vector<string> ans;

struct Trie {
    int next[500010][26], fail[500010], val[500010];
    int L;

    void init() {
        L = 1;
        memset(next[0], 0, sizeof(next[0]));
    }

    void insert(const char *str, int k) {
        int u = 0, n = static_cast<int>(strlen(str));

        for (int i = 0; i < n; i++) {
            int v = str[i] - 'a';
            if (next[u][v] == 0) {
                val[L] = 0;
                memset(next[L], 0, sizeof(next[L]));
                next[u][v] = L++;
            }
            u = next[u][v];
        }
        val[u] |= (1 << k);
    }

    void build() {
        queue<int> que;

        for (int i = 0; i < CharCnt; i++) {
            int u = next[0][i];
            if (u != 0) {
                fail[u] = 0;
                que.push(u);
            }
        }

        while (!que.empty()) {
            int r = que.front();
            que.pop();

            for (int i = 0; i < CharCnt; i++) {
                int u = next[r][i];

                if (u == 0) {
                    next[r][i] = next[fail[r]][i];
                    continue;
                }

                que.push(u);
                int v = fail[r];
                while ((v != 0) && next[v][i] == 0)
                    v = fail[v];

                fail[u] = next[v][i];
                val[u] |= val[fail[u]];
            }
        }
    }


};

Trie ac;
ll n, m, cnt = 0;
string s;

//d：字符串长度    u：在trie中的位置   s：匹配的状态
ll solve(int d, int u, int s) {
    if (d >= n) //长度达到n
        return s == (1 << m) - 1 ? 1 : 0;   //是否覆盖了每一个模式串

    if (dp[d][u][s] != -1)
        return dp[d][u][s]; //记忆化

    ll &ret = dp[d][u][s];  //没访问过
    ret = 0;

    for (int i = 0; i < CharCnt; i++) { //DFS，枚举下一个字母
        ret += solve(d + 1, ac.next[u][i], s | ac.val[ac.next[u][i]]);
    }
    return ret;
}

void dfs(int d, int u, int s, const string &str) {
    if (d >= n) {
        if (s == (1 << m) - 1) {
            ans.push_back(str);
        }
        return;
    }
    if (dp[d][u][s] <= 0)
        return;

    for (int i = 0; i < CharCnt; i++) {
        dfs(d + 1, ac.next[u][i], s | ac.val[ac.next[u][i]], str + (char) ('a' + i));
    }
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    while (cin >> n >> m && (n + m != 0)) {
        ac.init();
        for (int i = 0; i < m; i++) {
            cin >> s;
            ac.insert(s.c_str(), i);
        }
        ac.build();
        memset(dp, -1, sizeof(dp));

        ll anscnt = solve(0, 0, 0);
        cout << "Case " << ++cnt << ": " << anscnt << " suspects" << "\n";
        if (anscnt <= 42) {
            ans.clear();
            dfs(0, 0, 0, "");
            sort(ans.begin(), ans.end());
            for (const string &s :ans) {
                cout << s << "\n";
            }
        }
    }
}
