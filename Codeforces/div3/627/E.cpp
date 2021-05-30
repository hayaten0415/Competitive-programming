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
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<vector<int>> dp(n + 1, vector<int>(h, 0));
  vector<vector<bool>> dp_ok(n + 1, vector<bool>(h, false));
  dp_ok[0][0] = true;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  rep(i, n){
    rep(j, h){
      if(!dp_ok[i][j])continue;
      int nd1 = j + A[i];
      int nd2 = j + A[i] - 1;
      nd1 %= h;
      nd2 %= h;
      dp_ok[i + 1][nd1] = true;
      dp_ok[i + 1][nd2] = true;
      if(l <= nd1 && nd1 <= r){
        chmax(dp[i + 1][nd1], dp[i][j] + 1);
      }else{
        chmax(dp[i + 1][nd1], dp[i][j]);
      }
      if(l <= nd2 && nd2 <= r){
        chmax(dp[i + 1][nd2], dp[i][j] + 1);
      }else{
        chmax(dp[i + 1][nd2], dp[i][j]);
      }
    }
  }
  int ans = 0;
  rep(i, h){
    chmax(ans, dp[n][i]);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}