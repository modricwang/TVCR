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
    long double rat = log(2) / log(10);
    long long m;
    int cnt = 0;

    while (cin >> m) {
        cnt++;
        cout << "Case #" << cnt << ": " << (long long) (m * rat) << "\n";
    }
}