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
    int n;
    cin >> n;
    int a = n / 2;
    if (n % 2 == 0) a--;
    int b = n - a;
    while (__gcd(a, b) != 1) {
        a--;
        b++;
    }
    cout << a << " " << b << "\n";
}