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

//verify https://atcoder.jp/contests/arc054/tasks/arc054_b
//最小値を求めるパターン
int main() {
  long double p;
  cin >> p;
  auto f = [&](long double x){
    return x + p * powl(0.5L, x/ 1.5L);
  };
  long double left = 0.0L, right = p;
  rep(i, 200){
    long double t1 = (2.0L * left + right) / 3.0;
    long double t2 = (left + 2.0L * right) / 3.0;
    if(f(t1) > f(t2)){
      left = t1;
    }else{
      right = t2;
    }
  }
  cout << fixed << setprecision(10) << f(left) << endl;
}