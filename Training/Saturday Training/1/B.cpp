#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const double PI = acos(-1.0);

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
// Vector operator * (Vector A,double p)  {  return Vector(A.x*p, A.y*p);}
// Vector operator / (Vector A,double p)  {  return Vector(A.x/p, A.y/p);}

bool operator<(Point A, Point B) {
  return A.x < B.x || (A.x == B.x && A.y < B.y);
}

const double eps = 1e-10;
int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
bool operator==(Point A, Point B) {
  return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
// double Angle(Vector A,Vector B)  {  return acos( Dot(A, B) / Length(A) /
// Length(B) ) ;}
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
// Vector Rotate(Vector A,double rad)  {  double c=cos(rad),s=sin(rad);  return
// Vector(A.x*c-A.y*s, A.x*s+A.y*c);}

int ConvexHull(Point *p, int n, Point *ch) {
  sort(p, p + n);

  int m = 0;
  for (int i = 0; i < n; i++) {
    while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
      m--;
    ch[m++] = p[i];
  }

  int k = m;
  for (int i = n - 2; i >= 0; i--) {
    while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
      m--;
    ch[m++] = p[i];
  }

  if (m > 1)
    m--;
  return m;
}

const int L = 2000;
const int N = 50 * L + 50 * 3;
int n, m;
Point p[N + 10], q[N + 10];
int pn, qn;

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  while (scanf("%d%d", &n, &m) != EOF) {
    pn = 0;
    double x, y, r;
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf%lf", &x, &y, &r);
      for (int j = 0; j < L; j++)
        p[pn++] =
            Point(x + r * cos(PI * 2 * j / L), y + r * sin(PI * 2 * j / L));
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= 3; j++) {
        scanf("%lf%lf", &x, &y);
        p[pn++] = Point(x, y);
      }
    }

    qn = ConvexHull(p, pn, q);

    double ans = 0;
    for (int i = 0; i < qn; i++)
      ans += Length(q[(i + 1) % qn] - q[i]);

    printf("%lf\n", ans);
  }
  return 0;
}
