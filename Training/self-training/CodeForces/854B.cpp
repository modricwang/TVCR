#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    long long n, k;
    cin >> n >> k;
    long long Min, Max;
    if (k != 0 && k != n) Min = 1;
    else Min = 0;
    Max = min(k * 2, n - k);
    cout << Min << " " << Max << "\n";
}