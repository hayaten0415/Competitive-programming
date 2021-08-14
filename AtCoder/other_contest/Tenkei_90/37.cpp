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
const ll INF = (1LL << 60);
ll dp[501][10001];

ll op(ll a, ll b) { return max(a, b); }
ll e() { return -INF; }

int main() {
  int w, n;
  cin >> w >> n;
  vector<int> L(n), R(n);
  vector<ll> V(n);
  rep(i, n) cin >> L[i] >> R[i] >> V[i];
  vector<ll> W(w + 2, -INF);
  segtree<ll, op, e> tmp(W);
  rep(i, n+ 1)rep(j, w+1)dp[i][j] = -INF;
  dp[0][0] = 0;
  vector<segtree<ll, op, e>> seg(n+1, tmp);
  seg[0].set(0, 0);
  rep(i, n){
    rep(j, w + 1){
      chmax(dp[i + 1][j], dp[i][j]);
      int left = max(0, j - R[i]), right = max(0, j - L[i] + 1);
      if(left == right)continue;
      ll val = seg[i].prod(left, right);
      if(val != -INF)chmax(dp[i + 1][j], val + V[i]);
    }
    rep(j, w + 1){
      seg[i+1].set(j, dp[i+1][j]);
    }
  }
  if(dp[n][w] == -INF){
    cout << -1 << endl;
  }else{
    cout << dp[n][w] << endl;
  }
}