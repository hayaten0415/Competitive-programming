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


void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> cn(n+1);
  vector<int> A(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
    if(i - A[i] < 0)continue;
    cn[i - A[i]].pb(i);
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  dp[0][0] = cn[0].size();
  rep(i, n){
    rep(j, i+1){
      chmax(dp[i + 1][j], dp[i][j]);
      int a = lower_bound(ALL(cn[j]), i) - cn[j].begin();
      int b = cn[j].size();
      int c = lower_bound(ALL(cn[j+1]), i+1) - cn[j+1].begin();
      int d = cn[j + 1].size();
      chmax(dp[i + 1][j + 1], dp[i][j] - (b - a) + (d - c));
    }
  }
  int ans = INT_MAX;
  rep(i, n + 1) rep(j, n + 1) if (dp[i][j] >= k) chmin(ans, j);
  if(ans == INT_MAX)ans = -1;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}