#include <iostream>

using std::max;

const int MaxN = (int) 1e5 + 7;
int bit;
int d[MaxN];

void build(int n) {
    for (bit = 1; bit <= n + 1; bit <<= 1);
    for (int i = bit + 1; i <= bit + n; i++) {
        //add value
        //scanf("%d", &d[i]);
    }
    for (int i = bit - 1; i; i--)
        d[i] = max(d[i << 1], d[i << 1 | 1]);
    //i<<1|1 = (i<<1)+1 = 2*i+1
}

//单点修改
void update(int x, int y) {
    for (d[x += bit] = y, x >>= 1; x; x >>= 1)
        d[x] = max(d[x << 1], d[x << 1 | 1]);
}

//区间最大值
int query(int s, int t) {
    int ans = -1;
    for (s += bit - 1, t += bit + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1)
            ans = max(ans, d[s ^ 1]);
        if (t & 1)
            ans = max(ans, d[t ^ 1]);
    }
    return ans;
}

int main() {

}
