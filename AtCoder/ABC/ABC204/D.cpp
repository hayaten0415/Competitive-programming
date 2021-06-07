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

int main() {
  int n;
  cin >> n;
  vector<int> T(n);
  rep(i, n) cin >> T[i];
  int res1 = 0, res2 = 0;
  vector<int> T_sum(n + 1, 0);
  sort(ALL(T), greater{});
  rep(i, n){
    T_sum[i + 1] = T_sum[i] + T[i];
  }
  int ans = T_sum[n];
  vector<vector<bool>> dp(n + 1, vector<bool>(100001));
  dp[0][0] = true;
  rep(i, n){
    rep(j, 100001){
      if(!dp[i][j])continue;
      if(j + T[i] <=100000)dp[i+1][j+T[i]] = true;
      dp[i+1][j] = true;
    }
  }
  rep(j, 100001){
    if(dp[n][j])chmin(ans, max(j, T_sum[n] - j));
  }
  cout << ans << endl;
}