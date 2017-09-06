#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pi;

const int MaxN = 300000 + 7;

long long order[MaxN];
long long c[MaxN];

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    long long ans = 0;
    priority_queue<pi> pq;
    while (!pq.empty()) pq.pop();
    memset(order, 0, sizeof(order));
    for (int i = 1; i <= k; i++) {
        pq.emplace(c[i], i);
    }
    for (int i = k + 1; i <= n; i++) {
        pq.emplace(c[i], i);
        pi pp = pq.top();
        pq.pop();
        order[pp.second] = i;
        ans += c[pp.second] * (i - pp.second);
    }
    for (int i = n + 1; i <= n + k; i++) {
        pi pp = pq.top();
        pq.pop();
        order[pp.second] = i;
        ans += c[pp.second] * (i - pp.second);
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
        cout << order[i] << " ";
    }
    cout << "\n";
}