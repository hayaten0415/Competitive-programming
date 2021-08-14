#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
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
const long double PI = acosl(-1.0L);

int main() {
  long double t;
  long double l, x, y;
  cin >> t >> l >> x >> y;
  int q;
  cin >> q;
  cout << fixed << setprecision(8);
  rep(i, q){
    long double e;
    cin >> e;
    long double di = e / t * 360.0L;
    long double rad = PI * di / 180.0L;
    long double X = 0.0L;
    long double Y = l / (-2.0L) * sinl(rad);
    long double Z = l / 2.0L + l / (-2.0L) * cosl(rad);
    long double d1 = sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
    long double d2 = Z;
    long double kaku = atan2(d2, d1);
    cout << kaku * 180.0L / PI << endl;
  }
}