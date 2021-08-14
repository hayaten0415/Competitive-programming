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
using P = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n;
  cin >> n;
  vector<P> XY(n);
  vector<ll> X(n), Y(n);
  rep(i, n){
    cin >> X[i] >> Y[i];
    XY[i].first = X[i];
    XY[i].second = Y[i];
  }
  sort(ALL(X));
  sort(ALL(Y));
  ll x, y;
  if(n % 2 == 1){
    x = X[n / 2];
    y = Y[n / 2];
  }else{
    x = (X[n / 2] + X[n / 2 - 1]) / 2;
    y = (Y[n / 2] + Y[n / 2 - 1]) / 2;
  }
  ll res = 0;
  rep(i, n){
    res += abs(x - XY[i].first) + abs(y - XY[i].second);
  }
  cout << res << endl;
}