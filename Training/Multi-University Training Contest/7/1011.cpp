#include <iostream>

using namespace std;
const int MaxN = (int)1e7;
int nums[2 * MaxN + 7];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T, n, ptr;
  nums[1] = 1;
  nums[2] = 2;
  nums[3] = 2;
  // nums[4] = 1;
  ptr = 4;
  for (int i = 3; ptr <= MaxN; i++) {
    if (nums[i] == 2) {
      int nn = 3 - nums[ptr - 1];
      nums[ptr] = nums[ptr + 1] = nn;
      ptr += 2;
    } else {
      int nn = 3 - nums[ptr - 1];
      nums[ptr] = nn;
      ptr++;
    }
  }
  // for (int i=1; i<20; i++) cout<<nums[i]<<" ";
  cin >> T;
  while (T--) {
    cin >> n;
    cout << nums[n] << "\n";
  }
}
