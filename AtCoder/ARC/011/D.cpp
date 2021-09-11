#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;
const double PI = acos(-1);


// #define double long double
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
    bool operator!=(const Point &b) const { return !eq(x, b.x) || !eq(y, b.y); }
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
 
// ax + by + c = 0; 傾きは - a / b;
struct line{
    double a, b, c;
    line(): a(0), b(0), c(0) {}
    line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
    line(Point p1, Point p2): a(p2.y - p1.y), b(p1.x - p2.x), c(p2.cross(p1)) {}
    line(Point p1, double d): a(d), b(-1), c(-d*p1.x + p1.y) {};
    bool operator==(const line &L)const{ return eq(-c/b, -L.c/L.b) && eq(-(a+c)/b , -(L.a+L.c)/L.b); }
};
 
double distance_l_and_p(line a,Point b){
  return abs(a.a * b.x + a.b * b.y + a.c)/sqrt(pow(a.a,2) + pow(a.b,2));
}
 
Point crosspoint_l_and_l(line s, line t){
    return Point((t.c * s.b - s.c * t.b) / (s.a * t.b - t.a * s.b), (t.c * s.a - s.c * t.a) / (s.b * t.a - t.b * s.a));
}
 
//直線 p1-p2 と、直線 p3-p4 の交点
inline Point crosspoint(Point p1, Point p2, Point p3, Point p4){
    return (p2 - p1) * (p4 - p3).cross(p1 - p3) / (p2 - p1).cross(p4 - p3) + p1;
}
 
int ccw(Point a, Point b, Point c){
  if((b - a).cross(c - a) > EPS)return 1;
  if((b - a).cross(c - a) < -EPS)return -1;
  if((b - a).dot(c - a) < -EPS)return 2;
  if((b - a).abs() + EPS < (c - a).abs())return -2;
  return 0;
}
 
//線分a1-a2,b1-b2の交差判定
bool is_cross(Point a1, Point a2, Point b1, Point b2){
  if(a2 < a1) swap(a1, a2);
  if(b2 < b1) swap(b1, b2);
  if(ccw(a1,a2,b1)*ccw(a1,a2,b2) <= 0 && ccw(b1,b2,a1)*ccw(b1,b2,a2) <= 0){
    return true;
  }
  return false;
}
 
bool is_cross(line l1,line l2){
  if(abs(l1.a*l2.b-l2.a*l1.b)<EPS || abs(l1.a*l2.b-l2.a*l1.b)<EPS)return false;
  return true;
}
 
line point_bisector(Point p1,Point p2){
  return line(2.0*(p1.x-p2.x),2.0*(p1.y-p2.y),p2.x*p2.x+p2.y*p2.y-p1.x*p1.x-p1.y*p1.y);
}
 
line line_bisector1(line l1,line l2){
    line ret={l1.a+l2.a,l1.b+l2.b,l1.c+l2.c};
    return ret;
}
line line_bisector2(line l1,line l2){
    line ret={l1.a-l2.a,l1.b-l2.b,l1.c-l2.c};
    return ret;
}

//verify https://atcoder.jp/contests/abc197/tasks/abc197_d

int main() {
  ll n, m, r;
  cin >> n >> m >> r;
  vector<line> l(n);
  rep(i,n){
    double a,b,c;
    cin >> a >> b >> c;
    double s = sqrt(a*a+b*b);
    l[i].a = a/s;
    l[i].b = b/s;
    l[i].c = c/s;
  }
  vector<Point> p(m);
  rep(i,m){
    cin >> p[i];
    bool dup=false;
    rep(j,i) if(p[i]==p[j]) dup=true;
    if(dup) m--, i--;
  }
  auto md_to_line = [&](Point a){
    double d = numeric_limits<double>::max();
    rep(i,n){
      double d2 =pow(distance_l_and_p(l[i],a),2);
      if(d2 < d)d = d2;
    }
    return d;
  };

  auto md_to_point = [&](Point a){
    double d = numeric_limits<double>::max();
    rep(i,m){
      double d2 =(p[i] - a).abs2();
      if(d2 < d)d = d2;
    }
    return d;
  };

    auto f = [&](Point a){
      return sqrt(md_to_line(a)) + md_to_point(a);
    };
 
    vector<line> Cand;
    rep(i,n)rep(j,i)if(is_cross(l[i],l[j])){
      Cand.emplace_back(line_bisector1(l[i],l[j]));
      Cand.emplace_back(line_bisector2(l[i],l[j]));
    }
    rep(i,m)rep(j,i)if(p[i]!=p[j]){
      Cand.emplace_back(point_bisector(p[i],p[j]));
    }
    Cand.emplace_back(line(Point(-r,-r),Point(r,-r)));
    Cand.emplace_back(line(Point(-r,-r),Point(-r,r)));
    Cand.emplace_back(line(Point(r,r),Point(-r,r)));
    Cand.emplace_back(line(Point(r,r),Point(r,-r)));
    double ans = 0;
    ll N = Cand.size();
    rep(i,N)rep(j,i)if(is_cross(Cand[i],Cand[j])){
      Point p = crosspoint_l_and_l(Cand[i],Cand[j]);
      if(-r-EPS<p.x && p.x < r+EPS && -r-EPS<p.y && p.y < r+EPS){
        chmax(ans,f(p));
      }
    }
    cout << ans << endl;

}