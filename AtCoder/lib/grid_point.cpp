#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const double PI = acos(-1);

const double EPS = 1e-9;
inline bool eq(double a, double b) { return fabs(b - a) < EPS; }
 
 
struct Point{
    double x, y;
    Point(): x(0), y(0) {}
    Point(double _x, double _y): x(_x), y(_y) {}
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const double b) const { return Point(x * b, y * b); }
    Point operator*(const Point &b) const { return Point(x * b.x - y * b.y, x * b.y + y * b.x); }
    Point operator/(const double b) const { return Point(x / b, y / b); }
    bool operator==(const Point &b) const { return eq(x, b.x) && eq(y, b.y); }
    bool operator<(const Point &b) const { return x != b.x ? x < b.x : y < b.y; }
    double cross(Point b){return this->x * b.y - this->y * b.x;}//外積
    double dot(Point b){return this->x * b.x + this->y * b.y;} //内積
    double distance(Point v){return sqrt((this->x - v.x)*(this->x - v.x) + (v.y - this->y)*(v.y - this->y));}
    double abs(){return sqrt(x * x + y * y);}
    double abs2(){return x * x + y * y;}
    double arg() { return atan2(y, x); }
    Point rotate(double theta) { return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y); }
    Point rotate90() { return Point(-y, x); }
    friend ostream &operator<<(ostream &os, Point &p) { return os << "(" << p.x << "," << p.y << ")"; }
    friend istream &operator>>(istream &is, Point &a) { return is >> a.x >> a.y; }
};
// ax + by + c = 0; 傾きは - b / a;
struct line{
    double a, b, c;
    line(): a(0), b(0), c(0) {}
    line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    line(Point p1, Point p2): a(p2.y - p1.y), b(p1.x - p2.x), c(p2.cross(p1)) {}
};

//verify https://atcoder.jp/contests/abc197/tasks/abc197_d

int main() {
  double n;
  cin >> n;
  cout << fixed << setprecision(20);
  Point P, Q;
  cin >> P.x >> P.y;
  cin >> Q.x >> Q.y;
  Point M = (P + Q) / 2;
  Point D = P - M;
  Point D2 = D.rotate(2 * PI / n);
  Point ans = D2 + M;
  cout << ans.x << ' ' << ans.y << endl;
}