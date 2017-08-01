#include <iostream>

using std::max;
using std::min;

const int MaxN = 1e5 + 7;

int bit;
int d[MaxN];

void build(int n) {
    for (bit = 1; bit <= n + 1; bit <<= 1);
    for (int i = bit + 1; i <= bit + n; i++) {
        //add values
        //scanf("%d", &d[i]);
    }
    for (int i = bit - 1; i; i--) {
        d[i] = min(d[i << 1], d[i << 1 | 1]);
        d[i << 1] -= d[i];
        d[i << 1 | 1] -= d[i];
    }
}

//单点更新
void update(int s, int x) {
    int tmp;
    for (d[s] += x; s > 1; s >>= 1) {
        tmp = max(d[s], d[s ^ 1]);
        d[s] -= tmp;
        d[s ^ 1] -= tmp;
        d[s >> 1] += tmp;
        s >>= 1;
    }
}

//单点查询
int query(int x) {
    int res = 0;
    while (x)
        res += d[x], x >>= 1;
    return res;
}

//区间查询
void range_update(int s, int t, int x) {
    int tmp;
    for (s += bit - 1, t += bit + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1)
            d[s ^ 1] = x;
        if (t & 1)
            d[t ^ 1] = x;
        tmp = min(d[s], d[s ^ 1]);
        d[s] -= tmp;
        d[s ^ 1] -= tmp;
        d[s >> 1] += tmp;
        tmp = min(d[t], d[t ^ 1]);
        d[t] -= tmp;
        d[t ^ 1] -= tmp;
        d[t >> 1] += tmp;
    }
    while (s > 1) {
        tmp = min(d[s], d[s ^ 1]);
        d[s] -= tmp;
        d[s ^ 1] -= tmp;
        d[s >>= 1] += tmp;
    }
}

//区间查询
int range_query(int s, int t) {
    int lans = -1, rans = -1, ans = -1;
    for (s += bit - 1, t += bit + 1; s ^ 1 ^ 1; s >>= 1, t >>= 1) {
        lans += d[s];
        rans += d[t];
        if (~s & 1)
            lans = max(lans, d[s ^ 1]);
        if (t & 1)
            rans = max(rans, d[t ^ 1]);
    }
    for (ans = max(lans, rans); s > 1;)
        ans += d[s >>= 1];
    return ans;
}
