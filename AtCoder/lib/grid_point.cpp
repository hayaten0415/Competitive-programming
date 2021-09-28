#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const double PI = acos(-1);




template <typename T> struct Point{
    static T EPS;
    T x, y;
    static void set_eps(T e) { EPS = e; }
    Point(): x(0), y(0) {}
    Point(T _x, T _y) : x(_x), y(_y) {}
    Point(const std::pair<T, T> &p) : x(p.first), y(p.second) {}
    Point(const std::complex<T> &p) : x(p.real()), y(p.imag()) {}
    complex<T> to_complex() const noexcept { return {x, y}; }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator*(const T b) const { return Point(x * b, y * b); }
    Point operator*(const Point &b) const { return Point(x * b.x - y * b.y, x * b.y + y * b.x); }
    Point operator/(const T b) const { return Point(x / b, y / b); }
    bool operator==(const Point &b) const noexcept { return x == b.x and y == b.y; }
    bool operator<(const Point &b) const noexcept { return x != b.x ? x < b.x : y < b.y; }
    bool operator!=(const Point &b) const noexcept { return !((*this) == b); }
    T cross(Point b) { return this->x * b.y - this->y * b.x; } //外積
    T dot(Point b) { return this->x * b.x + this->y * b.y; }   //内積
    T distance(Point v) { return sqrt((this->x - v.x) * (this->x - v.x) + (v.y - this->y) * (v.y - this->y)); }
    T abs() { return sqrt(x * x + y * y); }
    T abs2(){return x * x + y * y;}
    T abscross(Point p) const noexcept { return std::abs(cross(p)); }
    T arg() { return atan2(y, x); }
    T norm() const noexcept { return std::sqrt(x * x + y * y); }
    T norm2() const noexcept { return x * x + y * y; }
    Point normalized() const { return (*this) / this->norm(); }
    Point conj() const noexcept { return Point(x, -y); }
    Point rotate(double theta) { return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y); }
    Point rotate90() { return Point(-y, x); }
    friend ostream &operator<<(ostream &os, Point &p) { return os << "(" << p.x << "," << p.y << ")"; }
    friend istream &operator>>(istream &is, Point &a) { return is >> a.x >> a.y; }
};


template <> double Point<double>::EPS = 1e-9;
template <> long double Point<long double>::EPS = 1e-12;
template <> long long Point<long long>::EPS = 0;

template <typename T>
int ccw(const Point<T> &a, const Point<T> &b, const Point<T> &c) { // a->b->cの曲がり方
    Point<T> v1 = b - a;
    Point<T> v2 = c - a;
    if (v1.cross(v2) > Point<T>::EPS) return 1;   // 左折
    if (v1.cross(v2) < -Point<T>::EPS) return -1; // 右折
    if (v1.dot(v2) < -Point<T>::EPS) return 2;  // c-a-b
    if (v1.norm() < v2.norm()) return -2;           // a-b-c
    return 0;                                       // a-c-b
}

// Convex hull （凸包）
// return: IDs of vertices used for convex hull, counterclockwise
// include_boundary: If true, interior angle pi is allowed
template <typename T>
std::vector<int> convex_hull(const std::vector<Point<T>> &ps, bool include_boundary = false) {
    int n = ps.size();
    if (n <= 1) return std::vector<int>(n, 0);
    std::vector<std::pair<Point<T>, int>> points(n);
    for (size_t i = 0; i < ps.size(); i++) points[i] = std::make_pair(ps[i], i);
    std::sort(points.begin(), points.end());
    int k = 0;
    std::vector<std::pair<Point<T>, int>> qs(2 * n);
    auto ccw_check = [&](int c) { return include_boundary ? (c == -1) : (c <= 0); };
    for (int i = 0; i < n; i++) {
        while (k > 1 and ccw_check(ccw(qs[k - 2].first, qs[k - 1].first, points[i].first))) k--;
        qs[k++] = points[i];
    }
    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t and ccw_check(ccw(qs[k - 2].first, qs[k - 1].first, points[i].first))) k--;
        qs[k++] = points[i];
    }
    std::vector<int> ret(k - 1);
    for (int i = 0; i < k - 1; i++) ret[i] = qs[i].second;
    return ret;
}

// Solve r1 + t1 * v1 == r2 + t2 * v2
template <typename T>
Point<T> lines_crosspoint(Point<T> r1, Point<T> v1, Point<T> r2, Point<T> v2) {
    assert(v2.cross(v1) != 0);
    return r1 + v1 * (v2.cross(r2 - r1) / v2.cross(v1));
}

// Whether two segments s1t1 & s2t2 intersect or not (endpoints not included)
// Google Code Jam 2013 Round 3 - Rural Planning
// Google Code Jam 2021 Round 3 - Fence Design
template <typename T> bool intersect_open_segments(Point<T> s1, Point<T> t1, Point<T> s2, Point<T> t2) {
    if (s1 == t1 or s2 == t2) return false; // Not segment but point
    int nbad = 0;
    for (int t = 0; t < 2; t++) {
        Point<T> v1 = t1 - s1, v2 = t2 - s2;
        T den = v2.det(v1);
        if (den == 0) {
            if (s1.cross(v1) == s2.cross(v1)) {
                auto L1 = s1.dot(v1), R1 = t1.dot(v1);
                auto L2 = s2.dot(v1), R2 = t2.dot(v1);
                if (L1 > R1) std::swap(L1, R1);
                if (L2 > R2) std::swap(L2, R2);
                if (L1 > L2) std::swap(L1, L2), std::swap(R1, R2);
                return R1 > L2;
            } else {
                return false;
            }
        } else {
            auto num = v2.cross(s2 - s1);
            if ((0 < num and num < den) or (den < num and num < 0)) nbad++;
        }
        std::swap(s1, s2);
        std::swap(t1, t2);
    }
    return nbad == 2;
}

// Whether point p is on segment (s, t) (endpoints not included)
// Google Code Jam 2013 Round 3 - Rural Planning
template <typename PointNd> bool is_point_on_open_segment(PointNd s, PointNd t, PointNd p) {
    if (s == t) return false; // not segment but point
    if (p == s or p == t) return false;
    auto v = t - s, w = p - s;
    if (v.absdet(w)) return false;
    auto vv = v.dot(v), vw = v.dot(w);
    return vw > 0 and vw < vv;
}

// Convex cut
// Cut the convex polygon g by line p1->p2 and return the leftward one
template <typename T>
std::vector<Point<T>> convex_cut(const std::vector<Point<T>> &g, Point<T> p1, Point<T> p2) {
    assert(p1 != p2);
    std::vector<Point<T>> ret;
    for (int i = 0; i < (int)g.size(); i++) {
        const Point<T> &now = g[i], &nxt = g[(i + 1) % g.size()];
        if (ccw(p1, p2, now) != -1) ret.push_back(now);
        if ((ccw(p1, p2, now) == -1) xor (ccw(p1, p2, nxt) == -1)) {
            ret.push_back(lines_crosspoint(now, nxt - now, p1, p2 - p1));
        }
    }
    return ret;
}

// 2円の交点 (ABC157F)
template <typename T>
std::vector<Point<T>> IntersectTwoCircles(const Point<T> &Ca, double Ra, const Point<T> &Cb, double Rb) {
    double d = (Ca - Cb).norm();
    if (Ra + Rb < d) return {};
    double rc = (d * d + Ra * Ra - Rb * Rb) / (2 * d);
    double rs = sqrt(Ra * Ra - rc * rc);
    Point<T> diff = (Cb - Ca) / d;
    return {Ca + diff * Point<T>(rc, rs), Ca + diff * Point<T>(rc, -rs)};
}

// Solve |x0 + vt| = R (SRM 543 Div.1 1000, GCJ 2016 R3 C)
template <typename PointNd, typename Float>
std::vector<Float> IntersectCircleLine(const PointNd &x0, const PointNd &v, Float R) {
    Float b = Float(x0.dot(v)) / v.norm2();
    Float c = Float(x0.norm2() - Float(R) * R) / v.norm2();
    if (b * b - c < 0) return {};
    Float ret1 = -b + sqrtl(b * b - c) * (b > 0 ? -1 : 1);
    Float ret2 = c / ret1;
    return ret1 < ret2 ? std::vector<Float>{ret1, ret2} : std::vector<Float>{ret2, ret1};
}

// Distance between point p <-> line ab
template <typename PointFloat>
decltype(PointFloat::x) DistancePointLine(const PointFloat &p, const PointFloat &a, const PointFloat &b) {
    assert(a != b);
    return (b - a).abscross(p - a) / (b - a).norm();
}

// Distance between point p <-> line segment ab
template <typename PointFloat>
decltype(PointFloat::x) DistancePointSegment(const PointFloat &p, const PointFloat &a, const PointFloat &b) {
    if (a == b) {
        return (p - a).norm();
    } else if ((p - a).dot(b - a) <= 0) {
        return (p - a).norm();
    } else if ((p - b).dot(a - b) <= 0) {
        return (p - b).norm();
    } else {
        return DistancePointLine<PointFloat>(p, a, b);
    }
}


// ax + by + c = 0; 傾きは - b / a;
template <typename T> struct line{
    T a, b, c;
    line(): a(0), b(0), c(0) {}
    line(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    line(Point<T> p1, Point<T> p2): a(p2.y - p1.y), b(p1.x - p2.x), c(p2.cross(p1)) {}
};


//verify https://atcoder.jp/contests/abc197/tasks/abc197_d

int main() {
  double n;
  cin >> n;
  cout << fixed << setprecision(20);
  Point<double> P, Q;
  cin >> P.x >> P.y;
  cin >> Q.x >> Q.y;
  Point M = (P + Q) / 2;
  Point D = P - M;
  Point D2 = D.rotate(2 * PI / n);
  Point ans = D2 + M;
  cout << ans.x << ' ' << ans.y << endl;
}