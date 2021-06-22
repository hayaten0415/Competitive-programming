#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
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

static const long double RATIO = (1.0L + sqrtl(5.0L)) * 0.5L;


//verify https://atcoder.jp/contests/arc054/tasks/arc054_b
//最小値を求めるパターン
int main() {
  long double p;
  cin >> p;
  auto f = [&](long double x){
    return x + p * powl(0.5L, x/ 1.5L);
  };
  auto GoldenSectionSearch = [&](long double left, long double right) {
    rep(i, 140){
      long double t1 = right - (right - left) / RATIO;
      long double t2 = left + (right - left) / RATIO;
      if(f(t1) < f(t2)){
        right = t2;
      }else{
        left = t1;
      }
    }
    return (left + right) * 0.5L;
  };
  cout << fixed << setprecision(10) << f(GoldenSectionSearch(0.0L, p)) << endl;
}