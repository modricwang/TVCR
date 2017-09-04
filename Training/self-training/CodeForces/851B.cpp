#include <iostream>

using namespace std;

inline long long Sqr(long long a) {
    return a * a;
}

inline long long dis2(long long ax, long long ay, long long bx, long long by) {
    return Sqr(ax - bx) + Sqr(ay - by);
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    long long ab2, bc2;
    ab2 = dis2(ax, ay, bx, by);
    bc2 = dis2(bx, by, cx, cy);
    long long dx1, dy1, dx2, dy2;
    dx1 = ax - bx;
    dx2 = bx - cx;
    dy1 = ay - by;
    dy2 = by - cy;
    long long det = dx1 * dy2 - dx2 * dy1;
    if (ab2 == bc2 && det != 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}