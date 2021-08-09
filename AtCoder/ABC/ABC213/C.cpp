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
const ll INF = (1LL <<60);

template <typename T>
vector<T> compress(vector<T> &X) {
  // ソートした結果を vals に
  vector<T> vals = X;
  sort(vals.begin(), vals.end());
  // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  // 各要素ごとに二分探索で位置を求める
  for (int i = 0; i < (int)X.size(); i++) {
    X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
  }
  return vals;
}

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> X(n), Y(n);
  rep(i, n) cin >> X[i] >> Y[i];
  vector<int> res_x = compress(X);
  vector<int> res_y = compress(Y);
  rep(i, n){
    cout << X[i] + 1 << " " << Y[i] + 1 << endl;
  }
}