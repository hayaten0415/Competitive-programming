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

struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
  point operator +(point P){
    return point(x + P.x, y + P.y);
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
  point operator /(double k){
    return point(x / k, y / k);
  }
};
point rotate(point P, double t){
  return point(P.x * cos(t) - P.y * sin(t), P.x * sin(t) + P.y * cos(t));
}

int main() {
  double n;
  cin >> n;
  cout << fixed << setprecision(20);
  point P, Q;
  cin >> P.x >> P.y;
  cin >> Q.x >> Q.y;
  point M = (P + Q) / 2;
  point D = P - M;
  point D2 = rotate(D, 2 * PI / n);
  point ans = D2 + M;
  cout << ans.x << ' ' << ans.y << endl;
}