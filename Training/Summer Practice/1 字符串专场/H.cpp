#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int CharSet = 26;
const int MaxN = 300010;
const int MaxM = 32;

long long ans;
long long dp[MaxM][MaxN];
const int root(0);

struct Trie {
    long long next[MaxN][CharSet + 1], fail[MaxN], end[MaxN];
    int L;


    void init() {
        memset(next, 0, sizeof next);
        memset(end, 0, sizeof end);
        memset(fail, 0, sizeof fail);
        L = 0;
    }

    void insert(const char buf[]) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if (next[now][buf[i] - 'a'] == 0) {
                end[++L] = end[now] + 1;
                next[now][buf[i] - 'a'] = L;
                now = L;
            } else now = next[now][buf[i] - 'a'];

        }

    }

    void build() {
        queue<long long> Q;
        for (int i = 0; i < 26; i++)
            if (next[root][i])
                Q.push(next[root][i]);

        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            if (fail[now]) ans++;
            for (int i = 0; i < 26; i++)
                if (next[now][i] == 0) {
                    next[now][i] = next[fail[now]][i];
                    if (next[now][i]) {
                        dp[1][next[now][i]]++;
                        ans++;
                    }
                } else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }


};

Trie ac;

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif

    int n;
    string s;
    while (cin >> n && n) {
        ac.init();
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> s;
            ac.insert(s.c_str());
        }

        ac.build();


        bool f = true;
        for (int i = 2; f; i++) {
            f = false;
            for (int j = 1; j <= ac.L; j++)
                if (dp[i - 1][j]) {
                    for (int k = 0; k < 26; k++) {
                        int t;
                        t = ac.next[j][k];
                        if (ac.end[t] < i)
                            continue;
                        dp[i][t] += dp[i - 1][j];
                        f = true;
                    }
                }
            for (int j = 1; j <= ac.L; j++)
                ans += dp[i][j];
        }
        cout << ans << "\n";
    }
    return 0;
}
