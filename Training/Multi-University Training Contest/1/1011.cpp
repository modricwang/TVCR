#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

const int MaxLen = int(5 * 1e6 + 3);
const int MaxBit = 10;
const int MaxN = 1007;

bool m[MaxN][MaxBit];
char str[MaxLen];

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    long long n, k;
    int cnt = 0;

    while (cin >> n >> k) {
        cnt++;
        long long ans;
        if (k <= n) ans = k;
        else {
            k -= n;
            if (k % (n - 1) != 0) ans = k % (n - 1);
            else {
                if (k % (n - 1) == 0) {
                    if ((k / (n - 1)) % 2 == 0) ans = n;
                    else ans = n - 1;
                }
            }
        }
        cout << "Case #" << cnt << ": " << (long long) ans << "\n";
    }
}
