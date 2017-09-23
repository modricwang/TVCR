#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x) {
  if (fabs(x) < eps)
    return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}

struct Point {
  double x, y;
  int id;

  Point() {}

  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }

  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }

  //叉积
  double operator^(const Point &b) const { return x * b.y - y * b.x; }

  //点积
  double operator*(const Point &b) const { return x * b.x + y * b.y; }

  //绕原点旋转角度B（弧度值），后x,y的变化
  void transXY(double B) {
    double tx = x, ty = y;
    x = tx * cos(B) - ty * sin(B);
    y = tx * sin(B) + ty * cos(B);
  }
};

double dist(Point a, Point b) { return sqrt((a - b) * (a - b)); }

const int MAXN = 1010;
Point list[MAXN];
int Stack[MAXN], top;

//相对于list[0]的极角排序
bool _cmp(Point p1, Point p2) {
  double tmp = (p1 - list[0]) ^ (p2 - list[0]);
  if (sgn(tmp) > 0)
    return true;
  else if (sgn(tmp) == 0 && sgn(dist(p1, list[0]) - dist(p2, list[0])) <= 0)
    return true;
  else
    return false;
}

void Graham(int n) {
  Point p0;
  int k = 0;
  p0 = list[0];
  //找最下边的一个点
  for (int i = 1; i < n; i++) {
    if ((p0.y > list[i].y) || (p0.y == list[i].y && p0.x > list[i].x)) {
      p0 = list[i];
      k = i;
    }
  }
  swap(list[k], list[0]);
  sort(list + 1, list + n, _cmp);
  if (n == 1) {
    top = 1;
    Stack[0] = 0;
    return;
  }
  if (n == 2) {
    top = 2;
    Stack[0] = 0;
    Stack[1] = 1;
    return;
  }
  Stack[0] = 0;
  Stack[1] = 1;
  top = 2;
  for (int i = 2; i < n; i++) {
    while (top > 1 && sgn((list[Stack[top - 1]] - list[Stack[top - 2]]) ^
                          (list[i] - list[Stack[top - 2]])) <= 0)

      top--;
    Stack[top++] = i;
  }
}

const int N = 100;
int times;
int n;
Point p[N + 10];

int ans[N + 10];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      double x, y;
      cin >> x >> y;
      list[i] = Point(x, y);
      list[i].id = i;
    }
    Graham(n);
    if (top < n) {
      cout << "YES\n";
      memset(ans, 0, sizeof ans);
      for (int i = 0; i < top; ++i) {
        ans[list[Stack[i]].id] = 1;
      }
      for (int i = 0; i < n; ++i)
        if (ans[i])
          cout << 'A';
        else
          cout << 'B';
      cout << "\n";
    } else {
      if (top <= 3) {
        cout << "NO\n";
      } else {
        memset(ans, 0, sizeof(ans));
        cout << "YES\n";
        for (int i = 0; i < top; i++) {
          if (i & 1) {
            ans[list[Stack[i]].id] = 1;
          }
        }
        for (int i = 0; i < n; ++i)
          if (ans[i])
            cout << 'A';
          else
            cout << 'B';
        cout << "\n";
      }
    }
    //        for (int i = 0; i < top; i++) {
    //            cout << Stack[i] << " ";
    //        }
    //        cout << "\n";
  }
}

/*
 99
 4
 1 0
 3 0
 0 1
 4 1
 */
