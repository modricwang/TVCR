#include <iostream>

using namespace std;

const int MaxN = 1023;
const int D = 5;

long long points[MaxN][D];
bool Good[MaxN];
long long GoodCnt;

inline bool dot(int pid1, int pid2, int pid3) {
    long long sum = 0;
    for (int i = 0; i < D; i++) {
        sum += (points[pid2][i] - points[pid1][i]) * (points[pid3][i] - points[pid1][i]);
    }
    return sum > 0;
}

int main() {
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    long long n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            cin >> points[i][j];
        }
    }
    GoodCnt = n;
    for (int i = 0; i < n; i++) {
        Good[i] = true;
        for (int j = 0; j < n; j++) {
            if (!Good[i]) break;
            if (j == i) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (dot(i, j, k)) {
                    Good[i] = false;
                    GoodCnt--;
                    break;
                }
            }
        }
    }
    cout << GoodCnt << "\n";
    for (int i = 0; i < n; i++) {
        if (Good[i]) {
            cout << i + 1 << "\n";
        }
    }
}