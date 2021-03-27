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


int main() {
  double n;
  cin >> n;
  double x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  double center_x = (double)((double)(x0 + x1) / 2.0);
  double center_y = (double)((double)(y0 + y1) / 2.0);
  double rect = (double)(360.0 / (double)n);
  double x2 = x0 - center_x,  y2 = y0 - center_y;
  double ans_x = x2 * cos(M_PI * rect / 180.0) - y2 * sin(M_PI * rect / 180.0);
  double ans_y = x2 * sin(M_PI * rect / 180.0) + y2 * cos(M_PI * rect / 180.0);
  cout << fixed << setprecision(6) << ans_x + center_x << " " << fixed << setprecision(6) << ans_y + center_y << endl;
}