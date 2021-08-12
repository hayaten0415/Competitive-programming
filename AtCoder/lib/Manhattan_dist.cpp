#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
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
const auto INF = numeric_limits<T>::max();

//verify https://atcoder.jp/contests/abc178/tasks/abc178_e

int main() {
  int n;
  cin >> n;
  vector<ll> X(n), Y(n);
  ll mx_x = -INF<ll>, mn_x = INF<ll>, mx_y = -INF<ll>, mn_y = INF<ll>;
  rep(i, n){
    ll x, y;
    cin >> x >> y;
    X[i] = x + y;
    Y[i] = x - y;
    chmax(mx_x, X[i]);
    chmin(mn_x, X[i]);
    chmax(mx_y, Y[i]);
    chmin(mn_y, Y[i]);
  }
  cout << max(mx_x - mn_x, mx_y - mn_y) << endl;
}