#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 62);

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<ll>> dp(n, vector<ll>(2, INF));
  dp[0][0] = 0;
  dp[0][1] = k;
  vector<ll> A(n - 1), B(n - 1);
  rep(i, n - 1) cin >> A[i];
  rep(i, n - 1) cin >> B[i];
  for (int i = 1; i < n; i++){
    chmin(dp[i][0], min(dp[i-1][0] + A[i-1], dp[i-1][1] + A[i-1]));
    chmin(dp[i][1], min(dp[i - 1][0] + B[i - 1] + k, dp[i - 1][1] + B[i - 1]));
  }
  rep(i, n){
    cout << min(dp[i][0], dp[i][1]) << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}